#ifndef EAPE_PROJECTILE_HPP
#define EAPE_PROJECTILE_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "state.pb.h"

#include "drawable.hpp"

namespace eape {

  class Projectile : public Drawable {
   public:
    Projectile(sf::Vector2i destination,
               const SpriteController& sprite_controller);
    virtual ~Projectile() = default;

    sf::Vector2i get_destination() const;

    virtual eap::Projectile serialize() const = 0;

   private:
    eap::Projectile serialize_partially() const;  // TODO

   private:
    sf::Vector2i m_destination;  // TODO: Add thrown_by_id
  };

}  // namespace eape

#endif  // EAPE_PROJECTILE_HPP
