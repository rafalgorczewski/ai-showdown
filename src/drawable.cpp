#include <utility>

#include "drawable.hpp"

namespace eape {

  Drawable::Drawable(const SpriteController& sprite_controller)
      : m_sprite_controller(sprite_controller) {
  }

  Drawable::Drawable(SpriteController&& sprite_controller)
      : m_sprite_controller(std::move(sprite_controller)) {
  }

  Drawable::~Drawable() = default;

  SpriteController& Drawable::get_sprite_controller() & {
    return m_sprite_controller;
  }

  const SpriteController& Drawable::get_sprite_controller() const& {
    return m_sprite_controller;
  }

}  // namespace eape
