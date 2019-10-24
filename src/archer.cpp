#include "archer.hpp"

namespace eape {

  bool Archer::can_attack(const Map& map, Unit& enemy) const {
    return true;  // TODO
  }

  void Archer::attack(Unit& enemy) {
    // TODO
  }

  eap::Unit Archer::serialize() const {
    auto unit_proto = serialize_partially();
    unit_proto.set_class_(eap::Class::ARCHER);
    return unit_proto;
  }

}  // namespace eape
