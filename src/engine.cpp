#include "engine.hpp"

#include <cstdlib>

#include "mapparser.hpp"

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
    load_state();

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

  void Engine::load_textures() {
    m_textures_manager.load();
  }

  void Engine::create_initial_state() {
    // TODO
  }

  void Engine::load_state() {
    // TODO
  }

  void Engine::run_lhs_bot() {
    // std::system(m_lhs_bot_path.c_str());
  }

  void Engine::run_rhs_bot() {
    // std::system(m_rhs_bot_path.c_str());
  }

  void Engine::apply_result() {
    // TODO
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
    m_window.setView(m_view);
  }

  void Engine::update_environment() {
    // TODO
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
  }

  void Engine::draw_projectiles() {
    // TODO
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
