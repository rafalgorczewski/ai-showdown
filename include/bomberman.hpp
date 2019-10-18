#ifndef EAPE_BOMBERMAN_HPP
#define EAPE_BOMBERMAN_HPP

#include "map.hpp"
#include "unit.hpp"

namespace eape {

  class Bomberman : public Unit {
   public:
    using Unit::Unit;

    bool can_attack(const Map& map, Unit& enemy) const override;
    void attack(Unit& enemy) override;
  };

}  // namespace eape

#endif  // EAPE_BOMBERMAN_HPP
