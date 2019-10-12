#ifndef EAPE_ENGINE_HPP
#define EAPE_ENGINE_HPP

#include <memory>
#include <string>
#include <vector>

#include "map.hpp"
#include "unit.hpp"
#include "window.hpp"

namespace eape {

  class Engine {
   public:
    void load(const std::string& map_path);
    bool is_running() const;
    void update();

   private:
    void load_map(const std::string& map_path);

   private:
    Window m_window{ { 1280, 900 }, "Es Aj Pokazdowna" };

    Map m_map;
    std::vector<std::shared_ptr<Unit>> m_lhs_units;
    std::vector<std::shared_ptr<Unit>> m_rhs_units;
  };

}  // namespace eape

#endif  // EAPE_ENGINE_HPP
