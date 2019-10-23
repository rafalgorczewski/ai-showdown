#include "projectile.hpp"

namespace eape {

  Projectile::Projectile(int thrown_by_id,
                         sf::Vector2i destination,
                         const SpriteController& sprite_controller)
      : Drawable(sprite_controller),
        m_thrown_by_id(thrown_by_id),
        m_destination(destination) {
  }

  sf::Vector2i Projectile::get_destination() const {
    return m_destination;
  }

  eap::Projectile Projectile::serialize_partially() const {
    eap::Projectile projectile_proto;

    projectile_proto.set_thrown_by_unit_id(m_thrown_by_id);
    projectile_proto.mutable_position()->set_x(m_destination.x);
    projectile_proto.mutable_position()->set_y(m_destination.y);

    return unit_proto;
  }

}  // namespace eape
