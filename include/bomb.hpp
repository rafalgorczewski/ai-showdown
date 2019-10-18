#ifndef EAPE_BOMB_HPP
#define EAPE_BOMB_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "projectile.hpp"

namespace eape {

  class Bomb : public Projectile {
   public:
    using Projectile::Projectile;
  };

}  // namespace eape

#endif
