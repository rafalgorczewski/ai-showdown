#ifndef EAPE_PROJECTILESFACTORY_HPP
#define EAPE_PROJECTILESFACTORY_HPP

#include <memory>
#include <type_traits>
#include <utility>

#include <SFML/Graphics.hpp>

#include "arrow.hpp"
#include "bomb.hpp"
#include "projectile.hpp"
#include "texturesmanager.hpp"

namespace eape {

  class ProjectilesFactory {
   public:
    explicit ProjectilesFactory(TexturesManager* textures_manager);

    template <typename ProjectileType>
    requires std::is_base_of_v<Projectile,
                               std::remove_cvref_t<ProjectileType>> auto
    build(int thrown_by_id, sf::Vector2i destination) {
      return build(std::type_identity<std::remove_cvref_t<ProjectileType>>{},
                   thrown_by_id,
                   destination);
    }

   private:
    std::shared_ptr<Arrow> build(std::type_identity<Arrow>,
                                 int thrown_by_id sf::Vector2i destination);
    std::shared_ptr<Bomb> build(std::type_identity<Bomb>,
                                int thrown_by_id sf::Vector2i destination);

    TexturesManager* m_textures_manager;
  };

}  // namespace eape

#endif
