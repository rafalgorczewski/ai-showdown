#include "bomb.hpp"

namespace eape {

  eap::Projectile Bomb::serialize() const {
    auto projectile_proto = serialize_partially();

    projectile_proto.set_type(eap::Projectile::Type::Projectile_Type_BOMB);

    return projectile_proto;
  }

}  // namespace eape
