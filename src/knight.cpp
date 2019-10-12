#include "knight.hpp"

namespace eape {

  bool Knight::can_attack(const Map& map, Unit& enemy) const {
    return true;  // TODO
  }

  void Knight::attack(Unit& enemy) const {
    // TODO
  }

  std::string Knight::get_texture_name() const {
    return "knight";
  }

}  // namespace eape
