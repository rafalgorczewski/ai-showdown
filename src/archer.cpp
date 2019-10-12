#include "archer.hpp"

namespace eape {

  bool Archer::can_attack(const Map& map, Unit& enemy) const {
    return true;
  }

  void Archer::attack(Unit& enemy) const {
  }

}  // namespace eape
