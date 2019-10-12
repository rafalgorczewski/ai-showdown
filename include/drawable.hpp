#ifndef EAPE_DRAWABLE_HPP
#define EAPE_DRAWABLE_HPP

#include <SFML/Graphics.hpp>

#include "spritecontroller.hpp"

namespace eape {

  class Drawable {
   public:
    Drawable(const SpriteController& sprite_controller);
    Drawable(SpriteController&& sprite_controller);
    virtual ~Drawable() = 0;

    SpriteController& get_sprite_controller() &;
    const SpriteController& get_sprite_controller() const&;
    const SpriteController& get_sprite_controller() const&& = delete;

   private:
    SpriteController m_sprite_controller;
  };

}  // namespace eape

#endif  // EAPE_DRAWABLE_HPP
