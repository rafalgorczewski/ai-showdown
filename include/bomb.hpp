#ifndef EAPE_BOMB_HPP
#define EAPE_BOMB_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "projectile.hpp"

namespace eape {

  class Bomb : public Projectile {
   public:
    using Projectile::Projectile;

    eap::Projectile serialize() const override;
  };

}  // namespace eape

#endif
