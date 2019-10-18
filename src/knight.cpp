#include "knight.hpp"

namespace eape {

  bool Knight::can_attack(const Map& map, Unit& enemy) const {
    return true;  // TODO
  }

  void Knight::attack(Unit& enemy) {
    // TODO
    use_animation("chuj");
  }

}  // namespace eape
