#ifndef EAPE_UNIT_HPP
#define EAPE_UNIT_HPP

#include <SFML/Graphics.hpp>

#include "map.hpp"

namespace eape {

  class Unit {
   public:
    virtual ~Unit() = default;

    virtual bool can_attack(const Map& map, Unit& enemy) const = 0;
    virtual void attack(Unit& enemy) const = 0;

   private:
    int id;
    sf::Vector2i position;
  };

}  // namespace eape

#endif  // EAPE_UNIT_HPP
