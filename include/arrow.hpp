#ifndef EAPE_ARROW_HPP
#define EAPE_ARROW_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "projectile.hpp"

namespace eape {

  class Arrow : public Projectile {
   public:
    using Projectile::Projectile;
  };

}  // namespace eape

#endif
