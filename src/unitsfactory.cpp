#include "unitsfactory.hpp"
#include "spritecontroller.hpp"

namespace eape {

  UnitsFactory::UnitsFactory(TexturesManager* textures_manager)
      : m_textures_manager(textures_manager) {
  }

  std::shared_ptr<Knight> UnitsFactory::build_knight(std::type_identity<Knight>,
                                                     int id,
                                                     sf::Vector2i position) {
    SpriteController sprite_controller((*m_textures_manager)["knight"]);
    return std::make_shared<Knight>(id, sprite_controller, position);
  }

  std::shared_ptr<Archer> UnitsFactory::build_archer(std::type_identity<Knight>,
                                                     int id,
                                                     sf::Vector2i position) {
    SpriteController sprite_controller((*m_textures_manager)["knight"]);
    return std::make_shared<Archer>(id, sprite_controller, position);
  }

  std::shared_ptr<Bomberman> UnitsFactory::build_bomberman(std::type_identity<Knight>,
                                                           int id,
                                                           sf::Vector2i position) {
    SpriteController sprite_controller((*m_textures_manager)["knight"]);
    return std::make_shared<Bomberman>(id, sprite_controller, position);
  }

}  // namespace eape
