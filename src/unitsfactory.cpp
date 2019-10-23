#include "unitsfactory.hpp"

#include "config.hpp"
#include "spritecontroller.hpp"

namespace eape {

  UnitsFactory::UnitsFactory(TexturesManager* textures_manager)
      : m_textures_manager(textures_manager) {
  }

  std::shared_ptr<Unit> UnitsFactory::deserialize(const eap::Unit& unit_proto) {
    switch (unit_proto.class()) {
      default:
        [[fallthrough]];
      case eap::Class::Knight: {
        return build<Knight>(
          unit_proto.id(),
          { unit_proto.position().x(), unit_proto.position().y() },
          unit_proto.health());
        break;
      }
      case eap::Class::Archer: {
        return build<Archer>(
          unit_proto.id(),
          { unit_proto.position().x(), unit_proto.position().y() },
          unit_proto.health());
        break;
      }
      case eap::Class::Bomberman: {
        return build<Bomberman>(
          unit_proto.id(),
          { unit_proto.position().x(), unit_proto.position().y() },
          unit_proto.health());
        break;
      }
    }
    return {};
  }

  std::shared_ptr<Knight> UnitsFactory::build(std::type_identity<Knight>,
                                              int id,
                                              sf::Vector2i position,
                                              std::optional<int> health) {
    SpriteController sprite_controller((*m_textures_manager)["knight"]);
    sprite_controller.add_animation("idle", { { 0, 0 }, { 24, 24 }, 2 });

    return std::make_shared<Knight>(
      id, sprite_controller, position, health.value_or(C_KNIGHT_HP));
  }

  std::shared_ptr<Archer> UnitsFactory::build(std::type_identity<Archer>,
                                              int id,
                                              sf::Vector2i position,
                                              std::optional<int> health) {
    SpriteController sprite_controller((*m_textures_manager)["archer"]);
    sprite_controller.add_animation("idle", { { 0, 0 }, { 24, 24 }, 2 });

    return std::make_shared<Archer>(
      id, sprite_controller, position, health.value_or(C_DEFAULT_HP));
  }

  std::shared_ptr<Bomberman> UnitsFactory::build(std::type_identity<Bomberman>,
                                                 int id,
                                                 sf::Vector2i position,
                                                 std::optional<int> health) {
    SpriteController sprite_controller((*m_textures_manager)["bomberman"]);
    sprite_controller.add_animation("idle", { { 0, 0 }, { 24, 24 }, 2 });

    return std::make_shared<Bomberman>(
      id, sprite_controller, position, health.value_or(C_DEFAULT_HP));
  }

}  // namespace eape
