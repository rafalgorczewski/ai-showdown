#include "knight.hpp"

namespace eape {

  bool Knight::can_attack(const Map& map, Unit& enemy) const {
    return true;  // TODO
  }

  void Knight::attack(Unit& enemy) {
    // TODO
  }

  eap::Unit Knight::serialize() const {
    auto unit_proto = serialize_partially();
    unit_proto.set_class_(eap::Class::KNIGHT);
    return unit_proto;
  }

}  // namespace eape
