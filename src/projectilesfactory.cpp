#include "projectilesfactory.hpp"

#include "spritecontroller.hpp"
#include "unitsfactory.hpp"

namespace eape {

  ProjectilesFactory::ProjectilesFactory(TexturesManager* textures_manager)
      : m_textures_manager(textures_manager) {
  }

  std::shared_ptr<Arrow> ProjectilesFactory::build(std::type_identity<Arrow>,
                                                   int thrown_by_id,
                                                   sf::Vector2i destination) {
    SpriteController sprite_controller((*m_textures_manager)["arrow"]);
    return std::make_shared<Arrow>(
      thrown_by_id, destination, sprite_controller);
  }

  std::shared_ptr<Bomb> ProjectilesFactory::build(std::type_identity<Bomb>,
                                                  int thrown_by_id,
                                                  sf::Vector2i destination) {
    SpriteController sprite_controller((*m_textures_manager)["bomb"]);
    return std::make_shared<Bomb>(thrown_by_id, destination, sprite_controller);
  }

}  // namespace eape
