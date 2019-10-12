#include "engine.hpp"
#include "mapparser.hpp"

namespace eape {

  const std::string STATE_FILENAME = "state.eaps";
  const std::string RESULT_FILENAME = "result.eapr";

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
    }
    else if (m_turn == Turn::Rhs) {
      run_rhs_bot();
    }
    apply_result();

    while (!next_turn_requested()) {
      handle_input();
      update_environment();
      draw();
    }

    flip_active_player();
  }

  void Engine::load_map(const std::string& map_path) {
    const MapParser map_parser(map_path);
    const auto& [map, units] = map_parser.parse_map();
    const auto& [lhs_units, rhs_units] = units;

    std::tie(m_map, m_lhs_units, m_rhs_units) = std::tie(map, lhs_units, rhs_units);

    for (auto lhs_unit : lhs_units) {
      m_sprite_controllers.emplace(lhs_unit->get_id(), SpriteController(m_textures_manager[lhs_unit->get_texture_name()]));
    }
    for (auto rhs_unit : rhs_units) {
      m_sprite_controllers.emplace(rhs_unit->get_id(), SpriteController(m_textures_manager[rhs_unit->get_texture_name()]));
    }
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
    // TODO
  }

  void Engine::run_rhs_bot() {
    // TODO
  }

  void Engine::apply_result() {
    // TODO
  }

  bool Engine::next_turn_requested() const {
    return {};  // TODO
  }

  void Engine::handle_input() {
    // TODO
  }

  void Engine::update_environment() {
    // TODO
  }

  void Engine::draw() {
    // TODO
  }

  void Engine::draw_map() {

  }

  void Engine::draw_units() {
    for (auto& [id, sprite_controller] : m_sprite_controllers) {
      m_window.draw(sprite_controller.get_sprite());
    }
  }

  void Engine::flip_active_player() {
    // TODO
  }

}  // namespace eape
