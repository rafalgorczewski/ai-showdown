#ifndef EAPE_DRAWABLE_HPP
#define EAPE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <chrono>

#include "spritecontroller.hpp"
#include "window.hpp"

namespace eape {

  class Drawable : private SpriteController {
   public:
    using SpriteController = SpriteController;
    Drawable(const SpriteController& sprite_controller);
    Drawable(SpriteController&& sprite_controller);
    virtual ~Drawable() = 0;

    void draw(Window& window);

   protected:
    using SpriteController::use_animation;

    void move_sprite(sf::Vector2i new_position);
    void move_sprite_by(sf::Vector2i offset);
    void smooth_move_sprite(
      sf::Vector2i new_position,
      std::chrono::milliseconds duration = std::chrono::milliseconds(1000));
    void smoothly_move_sprite_by(
      sf::Vector2i offset,
      std::chrono::milliseconds duration = std::chrono::milliseconds(1000));
  };

}  // namespace eape

#endif  // EAPE_DRAWABLE_HPP
