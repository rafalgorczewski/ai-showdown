#ifndef EAPE_ARROW_HPP
#define EAPE_ARROW_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "projectile.hpp"

namespace eape {

  class Arrow : public Projectile {
   public:
    using Projectile::Projectile;

    eap::Projectile serialize() const override;
  };

}  // namespace eape

#endif
