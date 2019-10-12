#include "archer.hpp"

namespace eape {

  bool Archer::can_attack(const Map& map, Unit& enemy) const {
    return true;  // TODO
  }

  void Archer::attack(Unit& enemy) const {
    // TODO
  }

  std::string Archer::get_texture_name() const {
    return "archer";
  }

}  // namespace eape
