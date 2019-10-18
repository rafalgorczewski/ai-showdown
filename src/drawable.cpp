#include "drawable.hpp"

#include <cmath>
#include <utility>

#include "config.hpp"

namespace eape {

  Drawable::Drawable(const SpriteController& sprite_controller)
      : SpriteController(sprite_controller) {
  }

  Drawable::Drawable(SpriteController&& sprite_controller)
      : SpriteController(std::move(sprite_controller)) {
  }

  Drawable::~Drawable() = default;

  void Drawable::draw(Window& window) {
    window.draw(SpriteController::get_sprite());
    SpriteController::update();
  }

  void Drawable::move_sprite(sf::Vector2i new_position) {
    SpriteController::get_sprite().setPosition(new_position.x * C_TILE_SIZE,
                                               new_position.y * C_TILE_SIZE);
  }

  void Drawable::move_sprite_by(sf::Vector2i offset) {
    SpriteController::get_sprite().setPosition(
      SpriteController::get_sprite().getPosition() +
      sf::Vector2f{ offset.x * C_TILE_SIZE, offset.y * C_TILE_SIZE });
  }

  void Drawable::smoothly_move_sprite(
    sf::Vector2i new_position,
    [[maybe_unused]] std::chrono::milliseconds duration) {
    // TODO
    move_sprite(new_position);
    arrive();
  }

  void Drawable::smoothly_move_sprite_by(
    sf::Vector2i offset, [[maybe_unused]] std::chrono::milliseconds duration) {
    // TODO
    move_sprite_by(offset);
    arrive();
  }

  void Drawable::arrive() {
    if (m_arrival_callback) {
      m_arrival_callback();
      m_arrival_callback = {};
    }
  }

  void Drawable::on_smooth_sprite_arrival(std::function<void()> callback) {
    m_arrival_callback = callback;
  }

}  // namespace eape
