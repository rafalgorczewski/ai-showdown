#ifndef EAPE_UNITSFACTORY_HPP
#define EAPE_UNITSFACTORY_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <type_traits>
#include <utility>

#include "archer.hpp"
#include "bomberman.hpp"
#include "knight.hpp"
#include "texturesmanager.hpp"
#include "unit.hpp"

namespace eape {

  class UnitsFactory {
   public:
    explicit UnitsFactory(TexturesManager* textures_manager);

    template <typename UnitType>
    requires std::is_base_of_v<Unit, std::remove_cvref_t<UnitType>> auto build(
      int id, sf::Vector2i position) {
      return build(
        std::type_identity<std::remove_cvref_t<UnitType>>{}, id, position);
    }

   private:
    std::shared_ptr<Knight> build(std::type_identity<Knight>,
                                  int id,
                                  sf::Vector2i position);
    std::shared_ptr<Archer> build(std::type_identity<Archer>,
                                  int id,
                                  sf::Vector2i position);
    std::shared_ptr<Bomberman> build(std::type_identity<Bomberman>,
                                     int id,
                                     sf::Vector2i position);

    TexturesManager* m_textures_manager;
  };

}  // namespace eape

#endif
