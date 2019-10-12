#include "engine.hpp"
#include "mapparser.hpp"

namespace eape {

  void Engine::load(const std::string& map_path) {
    load_map(map_path);
  }

  bool Engine::is_running() const {
    return m_window.isOpen();
  }

  void Engine::update() {
  }

  void Engine::load_map(const std::string& map_path) {
    const MapParser map_parser(map_path);
    const auto& [map, units] = map_parser.parse_map();
    const auto& [lhs_units, rhs_units] = units;

    std::tie(m_map, m_lhs_units, m_rhs_units) = std::tie(map, lhs_units, rhs_units);
  }

}  // namespace eape
