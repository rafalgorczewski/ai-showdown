#include "bomberman.hpp"

namespace eape {

  bool Bomberman::can_attack(const Map& map, Unit& enemy) const {
    return true;  // TODO
  }

  void Bomberman::attack(Unit& enemy) {
    // TODO
  }

  eap::Unit Bomberman::serialize() const {
    auto unit_proto = serialize_partially();
    unit_proto.set_class_(eap::Class::BOMBERMAN);
    return unit_proto;
  }

}  // namespace eape
