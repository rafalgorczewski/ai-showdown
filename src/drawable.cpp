#include "drawable.hpp"

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

  void Drawable::smooth_move_sprite(sf::Vector2i new_position,
                                    std::chrono::milliseconds duration) {
  }

  void Drawable::smoothly_move_sprite_by(sf::Vector2i offset,
                                         std::chrono::milliseconds duration) {
  }

}  // namespace eape
