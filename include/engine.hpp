#ifndef EAPE_ENGINE_HPP
#define EAPE_ENGINE_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "map.hpp"
#include "projectile.hpp"
#include "texturesmanager.hpp"
#include "unit.hpp"
#include "window.hpp"

namespace eape {

  class Engine {
   public:
    Engine(const std::string& lhs_bot_path, const std::string& rhs_bot_path);

    void load(const std::string& map_path);
    bool is_running() const;
    void update();

   private:
    enum class Turn { Lhs, Rhs };

   private:
    void load_map(const std::string& map_path);
    void create_initial_state();

    void load_state();
    void load_textures();
    void run_lhs_bot();
    void run_rhs_bot();
    void apply_result();

    bool next_turn_requested() const;

    void handle_input();
    void handle_arrow_keys();
    void update_environment();
    void clean();
    void draw();
    void draw_map();
    void draw_units();
    void draw_projectiles();
    void flush();

    void flip_active_player();

   private:
    std::string m_lhs_bot_path;
    std::string m_rhs_bot_path;

    Window m_window;
    sf::View m_view;

    Turn m_turn = Turn::Lhs;

    Map m_map;
    std::vector<std::shared_ptr<Unit>> m_lhs_units;
    std::vector<std::shared_ptr<Unit>> m_rhs_units;

    TexturesManager m_textures_manager;
  };

}  // namespace eape

#endif  // EAPE_ENGINE_HPP
