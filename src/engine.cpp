#include "engine.hpp"

#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <execution>

#include "state.pb.h"
#include "result.pb.h"

#include "mapparser.hpp"
#include "unitsfactory.hpp"
#include "projectilesfactory.hpp"

namespace eape {

  const std::string STATE_FILENAME = "state.eaps";
  const std::string RESULT_FILENAME = "result.eapr";

  const sf::Vector2u WINDOW_SIZE = { 1280, 900 };

  Engine::Engine(const std::string& lhs_bot_path,
                 const std::string& rhs_bot_path)
      : m_lhs_bot_path(lhs_bot_path),
        m_rhs_bot_path(rhs_bot_path),
        m_window(WINDOW_SIZE, "Es Aj Pokazdowna"),
        m_view({ 0,
                 0,
                 static_cast<float>(WINDOW_SIZE.x),
                 static_cast<float>(WINDOW_SIZE.y) }) {
    m_window.setView(m_view);
  }

  void Engine::load(const std::string& map_path) {
    load_textures();
    load_map(map_path);
    create_initial_state();
  }

  bool Engine::is_running() const {
    return m_window.isOpen();
  }

  void Engine::update() {
    clear_state();
    load_state();
    recolour_units();

    if (m_turn == Turn::Lhs) {
      run_lhs_bot();
    } else if (m_turn == Turn::Rhs) {
      run_rhs_bot();
    }
    apply_result();

    while (!next_turn_requested()) {
      clean();
      handle_input();
      update_environment();
      draw();
      flush();
    }

    flip_active_player();
  }

  void Engine::load_map(const std::string& map_path) {
    const MapParser map_parser(map_path);
    const auto [map, units] = map_parser.parse_map(m_textures_manager);
    const auto& [lhs_units, rhs_units] = units;

    std::tie(m_map, m_lhs_units, m_rhs_units) =
      std::tie(map, lhs_units, rhs_units);
  }

  void Engine::recolour_units() {
    for (auto lhs_unit : m_lhs_units) {
      lhs_unit->tint(sf::Color::Red);
    }
    for (auto rhs_unit : m_rhs_units) {
      rhs_unit->tint(sf::Color::Blue);
    }
  }

  void Engine::load_textures() {
    m_textures_manager.load();
  }

  void Engine::create_initial_state() {
    eap::State state_proto;
    state_proto.mutable_map()->CopyFrom(m_map.serialize_partially());

    const auto& ally_units =
      ((m_turn == Turn::Lhs) ? m_lhs_units : m_rhs_units);
    const auto& enemy_units =
      ((m_turn == Turn::Lhs) ? m_rhs_units : m_lhs_units);

    for (const auto unit : ally_units) {
      auto const ally_unit_proto = state_proto.mutable_map()->add_ally_units();
      ally_unit_proto->CopyFrom(unit->serialize());
    }
    for (const auto unit : enemy_units) {
      auto const enemy_unit_proto =
        state_proto.mutable_map()->add_enemy_units();
      enemy_unit_proto->CopyFrom(unit->serialize());
    }

    for (const auto projectile : m_projectiles) {
      auto const projectile_proto =
        state_proto.mutable_map()->add_projectiles();
      projectile_proto->CopyFrom(projectile->serialize());
    }

    std::ofstream state_stream(STATE_FILENAME);
    state_proto.SerializeToOstream(&state_stream);
  }

  void Engine::clear_state() {
    m_lhs_units.clear();
    m_rhs_units.clear();
    m_projectiles.clear();
  }

  void Engine::load_state() {
    std::ifstream state_stream(STATE_FILENAME);
    eap::State state_proto;
    state_proto.ParseFromIstream(&state_stream);

    UnitsFactory units_factory(&m_textures_manager);
    for (const auto& ally_unit_proto : state_proto.map().ally_units()) {
      m_lhs_units.push_back(units_factory.deserialize(ally_unit_proto));
    }
    for (const auto& enemy_unit_proto : state_proto.map().enemy_units()) {
      m_lhs_units.push_back(units_factory.deserialize(enemy_unit_proto));
    }

    ProjectilesFactory projectiles_factory(&m_textures_manager);
    for (const auto& projectile_proto : state_proto.map().projectiles()) {
      m_projectiles.push_back(
        projectiles_factory.deserialize(projectile_proto));
    }
  }

  void Engine::run_lhs_bot() {
    std::system(m_lhs_bot_path.c_str());
  }

  void Engine::run_rhs_bot() {
    std::system(m_rhs_bot_path.c_str());
  }

  void Engine::apply_result() {
    using std::begin, std::end;

    std::ifstream result_stream(RESULT_FILENAME);
    eap::Result result_proto;
    result_proto.ParseFromIstream(&result_stream);

    auto& current_units = ((m_turn == Turn::Lhs) ? m_lhs_units : m_rhs_units);

    for (const auto& action_proto : result_proto.actions()) {
      const auto unit_it =
        std::find_if(std::execution::par_unseq,
                     begin(current_units),
                     end(current_units),
                     [&action_proto](std::shared_ptr<Unit> unit) {
                       return unit->get_id() == action_proto.entity_id();
                     });
      if (unit_it == end(current_units)) {
        continue;
      }
      auto& action_unit = *unit_it;

      switch (action_proto.type()) {
        case eap::Action::Type::Action_Type_ATTACK: {
          const auto is_target = [&action_proto](std::shared_ptr<Unit> unit) {
            return unit->get_position() ==
                   sf::Vector2i{ action_proto.target_position().x(),
                                 action_proto.target_position().y() };
          };
          const auto target_lhs_unit_it =
            std::find_if(std::execution::par_unseq,
                         begin(m_lhs_units),
                         end(m_lhs_units),
                         is_target);
          const auto target_rhs_unit_it =
            std::find_if(std::execution::par_unseq,
                         begin(m_rhs_units),
                         end(m_rhs_units),
                         is_target);

          if (target_lhs_unit_it != end(m_lhs_units)) {
            action_unit->attack(**target_lhs_unit_it);
          } else if (target_rhs_unit_it != end(m_rhs_units)) {
            action_unit->attack(**target_rhs_unit_it);
          } else {
            // TODO: Miss
          }
          break;
        }
        case eap::Action::Type::Action_Type_MOVEMENT: {
          if (m_map.is_tile_passable({ action_proto.target_position().x(),
                                       action_proto.target_position().y() })) {
            action_unit->move({ action_proto.target_position().x(),
                                action_proto.target_position().y() });
          } else {
            // TODO: Miss
          }
          break;
        }
        default: {
          break;
        }
      }
    }
  }

  bool Engine::next_turn_requested() const {
    return false;  // TODO
  }

  void Engine::handle_input() {
    handle_arrow_keys();
  }

  void Engine::handle_arrow_keys() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      m_view.move({ 0, -5 });
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      m_view.move({ 0, 5 });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      m_view.move({ -5, 0 });
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      m_view.move({ 5, 0 });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) {
      m_view.zoom(0.5);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) {
      m_view.zoom(2.0);
    }
    m_window.setView(m_view);
  }

  void Engine::update_environment() {
    // TODO: ???
  }

  void Engine::clean() {
    m_window.clear();
  }

  void Engine::draw() {
    draw_map();
    draw_units();
    draw_projectiles();
  }

  void Engine::draw_map() {
    for (const auto& sprite : m_map.get_sprites(m_textures_manager)) {
      m_window.draw(sprite);
    }
  }

  void Engine::draw_units() {
    for (const auto lhs_unit : m_lhs_units) {
      lhs_unit->draw(m_window);
    }
    for (const auto rhs_unit : m_rhs_units) {
      rhs_unit->draw(m_window);
    }
  }

  void Engine::draw_projectiles() {
    for (const auto projectile : m_projectiles) {
      projectile->draw(m_window);
    }
  }

  void Engine::flush() {
    m_window.display();
  }

  void Engine::flip_active_player() {
    if (m_turn == Turn::Lhs) {
      m_turn = Turn::Rhs;
    } else if (m_turn == Turn::Rhs) {
      m_turn = Turn::Lhs;
    }
  }

}  // namespace eape
