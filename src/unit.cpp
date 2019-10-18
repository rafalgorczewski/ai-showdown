#include "unit.hpp"

namespace eape {

  Unit::Unit(int id,
             const SpriteController& sprite_controller,
             sf::Vector2i position)
      : Drawable(sprite_controller), m_id(id), m_position(position) {
  }

  int Unit::get_id() const {
    return m_id;
  }

  sf::Vector2i Unit::get_position() const {
    return m_position;
  }

  void Unit::set_position(sf::Vector2i new_position) {
    m_position = new_position;
  }

  void Unit::move_by(sf::Vector2i offset) {
    m_position += offset;
  }

}  // namespace eape
