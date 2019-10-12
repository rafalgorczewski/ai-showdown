#include "projectile.hpp"

namespace eape {

  Projectile::Projectile(sf::Vector2i destination,
                         const SpriteController& sprite_controller)
      : Drawable(sprite_controller), m_destination(destination) {
  }

  sf::Vector2i Projectile::get_destination() const {
    return m_destination;
  }

}  // namespace eape
