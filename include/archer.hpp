#ifndef EAPE_ARCHER_HPP
#define EAPE_ARCHER_HPP

#include "map.hpp"
#include "unit.hpp"

namespace eape {

  class Archer : public Unit {
   public:
    using Unit::Unit;

    bool can_attack(const Map& map, Unit& enemy) const override;
    void attack(Unit& enemy) override;
  };

}  // namespace eape

#endif  // EAPE_ARCHER_HPP
