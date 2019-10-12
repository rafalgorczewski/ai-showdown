#include "spritecontroller.hpp"

namespace eape {

  SpriteController::SpriteController(const sf::Texture& texture)
      : m_sprite(texture) {
  }

  void SpriteController::add_animation(const std::string& name,
                                       const Animation& animation) {
    if (animation_already_exists(name)) {
      // TODO: error
    } else {
      m_animations.emplace(name, animation);
    }
  }

  void SpriteController::use_animation(const std::string& name,
                                       AnimationMode animation_mode,
                                       int ms_per_frame) {
    if (!animation_already_exists(name)) {
      // TODO: error
    } else if (animation_mode == AnimationMode::Normal) {
      m_ms_per_normal_frame = ms_per_frame;
      reset_previous_normal_animation();
      select_as_normal_animation(name);
      reset_clock();
    } else if (animation_mode == AnimationMode::Immediate) {
      m_ms_per_immediate_frame = ms_per_frame;
      select_as_immediate_animation(name);
      reset_clock();
    }
  }

  void SpriteController::update() {
    if (!is_normal_animation_set()) {
      // TODO: error
    } else {
      if (is_immediate_animation_active()) {
        update_immediate_animation();
      } else {
        update_normal_animation();
      }
    }
  }

  sf::Sprite& SpriteController::get_sprite() & {
    return m_sprite;
  }

  const sf::Sprite& SpriteController::get_sprite() const& {
    return m_sprite;
  }

  bool SpriteController::animation_already_exists(
    const std::string& name) const {
    return m_animations.find(name) != m_animations.end();
  }

  bool SpriteController::is_normal_animation_set() const {
    return m_normal_animation != "";
  }

  bool SpriteController::is_immediate_animation_active() const {
    return m_immediate_animation != "";
  }

  void SpriteController::reset_previous_normal_animation() {
    if (m_normal_animation != "") {
      m_animations[m_normal_animation].reset_animation();
    }
  }

  void SpriteController::select_as_normal_animation(const std::string& name) {
    m_normal_animation = name;
    m_sprite.setTextureRect(
      m_animations[m_normal_animation].get_current_tile());
  }

  void SpriteController::select_as_immediate_animation(
    const std::string& name) {
    m_immediate_animation = name;
    m_sprite.setTextureRect(
      m_animations[m_immediate_animation].get_current_tile());
  }

  void SpriteController::reset_clock() {
    m_animation_clock.restart();
  }

  void SpriteController::update_immediate_animation() {
    if (elapsed_time() >= m_ms_per_immediate_frame) {
      if (are_immediate_frames_left()) {
        proceed_immediate_animation();
      } else {
        end_immediate_animation();
      }
      reset_clock();
    }
  }

  bool SpriteController::are_immediate_frames_left() {
    return m_animations[m_immediate_animation].tiles_left_for_full_sequence() >
           0;
  }

  void SpriteController::proceed_immediate_animation() {
    m_animations[m_immediate_animation].change_tile_to_next();
    m_sprite.setTextureRect(
      m_animations[m_immediate_animation].get_current_tile());
  }

  void SpriteController::end_immediate_animation() {
    m_animations[m_immediate_animation].reset_animation();
    m_immediate_animation = {};
    m_animations[m_normal_animation].change_tile_to_next();
    m_sprite.setTextureRect(
      m_animations[m_normal_animation].get_current_tile());
  }

  void SpriteController::update_normal_animation() {
    if (elapsed_time() >= m_ms_per_normal_frame) {
      proceed_normal_animation();
      reset_clock();
    }
  }

  void SpriteController::proceed_normal_animation() {
    m_animations[m_normal_animation].change_tile_to_next();
    m_sprite.setTextureRect(
      m_animations[m_normal_animation].get_current_tile());
  }

  int SpriteController::elapsed_time() const {
    return m_animation_clock.getElapsedTime().asMilliseconds();
  }

}  // namespace eape
