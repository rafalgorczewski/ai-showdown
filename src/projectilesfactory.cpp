#include "projectilesfactory.hpp"

#include "spritecontroller.hpp"
#include "unitsfactory.hpp"

namespace eape {

  ProjectilesFactory::ProjectilesFactory(TexturesManager* textures_manager)
      : m_textures_manager(textures_manager) {
  }

  std::shared_ptr<Arrow> ProjectilesFactory::build(std::type_identity<Arrow>,
                                                   sf::Vector2i destination) {
    SpriteController sprite_controller((*m_textures_manager)["arrow"]);
    return std::make_shared<Knight>(destination, sprite_controller);
  }

  std::shared_ptr<Bomb> ProjectilesFactory::build(std::type_identity<Bomb>,
                                                  sf::Vector2i destinationn) {
    SpriteController sprite_controller((*m_textures_manager)["bomb"]);
    return std::make_shared<Archer>(destination, sprite_controller);
  }

}  // namespace eape
