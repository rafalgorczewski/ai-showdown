#ifndef EAPE_PROJECTILE_HPP
#define EAPE_PROJECTILE_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.hpp"

namespace eape {

  class Projectile : public Drawable {
   public:
    Projectile(sf::Vector2i destination,
               const SpriteController& sprite_controller);
    virtual ~Projectile() = default;

    sf::Vector2i get_destination() const;

   private:
    sf::Vector2i m_destination;
  };

}  // namespace eape

#endif  // EAPE_PROJECTILE_HPP
