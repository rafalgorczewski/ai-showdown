#include "bomberman.hpp"

namespace eape {

  bool Bomberman::can_attack(const Map& map, Unit& enemy) const {
    return true;  // TODO
  }

  void Bomberman::attack(Unit& enemy) const {
    // TODO
  }

  std::string Bomberman::get_texture_name() const {
    return "bomberman";
  }

}  // namespace eape
