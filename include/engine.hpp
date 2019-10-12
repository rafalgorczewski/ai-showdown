#ifndef EAPE_ENGINE_HPP
#define EAPE_ENGINE_HPP

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "map.hpp"
#include "unit.hpp"
#include "window.hpp"
#include "spritecontroller.hpp"
#include "texturesmanager.hpp"

namespace eape {

  class Engine {
   public:
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
    void update_environment();
    void draw();
    void draw_map();
    void draw_units();

    void flip_active_player();

   private:
    Window m_window{ { 1280, 900 }, "Es Aj Pokazdowna" };

    Turn m_turn = Turn::Lhs;

    Map m_map;
    std::vector<std::shared_ptr<Unit>> m_lhs_units;
    std::vector<std::shared_ptr<Unit>> m_rhs_units;

    TexturesManager m_textures_manager;

    std::unordered_map<int, SpriteController> m_sprite_controllers;
  };

}  // namespace eape

#endif  // EAPE_ENGINE_HPP
