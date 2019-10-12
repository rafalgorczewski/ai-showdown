#ifndef EAPE_KNIGHT_HPP
#define EAPE_KNIGHT_HPP

#include "unit.hpp"

namespace eape {

  class Knight : public Unit {
    bool can_attack(const Map& map, Unit& enemy) const override;
    void attack(Unit& enemy) const override;
  };

}  // namespace eape

#endif  // EAPE_KNIGHT_HPP
