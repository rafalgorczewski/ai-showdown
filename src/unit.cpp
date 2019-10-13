#include "unit.hpp"

namespace eape {

  Unit::Unit(int id,
             const SpriteController& sprite_controller,
             sf::Vector2i position,
             int health)
      : Drawable(sprite_controller),
        m_id(id),
        m_health(health),
        m_position(position) {
    move_sprite(position);
    use_animation("idle");
  }

  void Unit::receive_damage(int damage) {
    use_animation("damaged", AnimationMode::Immediate);

    on_immediate_animation_end([this, damage] { m_health -= damage; });
  }

  void Unit::die() {
    use_animation("dying", AnimationMode::Immediate);
  }

  void Unit::move(sf::Vector2i new_position) {
    on_immediate_animation_end([this, new_position] {
      move_sprite(new_position);

      use_animation("falling", AnimationMode::Immediate);
    });
    use_animation("jumping", AnimationMode::Immediate);

    m_position = new_position;
  }

  void Unit::move_by(sf::Vector2i offset) {
    on_smooth_sprite_arrival([this] { use_animation("idle"); });
    use_animation("running");
    smoothly_move_sprite_by(offset);

    m_position += offset;
  }

  int Unit::get_id() const {
    return m_id;
  }

  sf::Vector2i Unit::get_position() const {
    return m_position;
  }

  bool Unit::is_dead() const {
    return m_health <= 0;
  }

  eap::Unit Unit::serialize_partially() const {
    eap::Unit unit_proto;

    unit_proto.set_id(m_id);
    unit_proto.mutable_position()->set_x(m_position.x);
    unit_proto.mutable_position()->set_y(m_position.y);
    unit_proto.set_health(m_health);

    return unit_proto;
  }

}  // namespace eape
