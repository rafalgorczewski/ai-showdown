#ifndef EAPE_UNITSFACTORY_HPP
#define EAPE_UNITSFACTORY_HPP

#include <memory>
#include <type_traits>
#include <utility>
#include <optional>

#include <SFML/Graphics.hpp>

#include "state.pb.h"

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
      int id, sf::Vector2i position, std::optional<int> health = std::nullopt) {
      return build(std::type_identity<std::remove_cvref_t<UnitType>>{},
                   id,
                   position,
                   health);
    }

    std::shared_ptr<Unit> deserialize(const eap::Unit& unit_proto);

   private:
    std::shared_ptr<Knight> build(std::type_identity<Knight>,
                                  int id,
                                  sf::Vector2i position,
                                  std::optional<int> health = std::nullopt);
    std::shared_ptr<Archer> build(std::type_identity<Archer>,
                                  int id,
                                  sf::Vector2i position,
                                  std::optional<int> health = std::nullopt);
    std::shared_ptr<Bomberman> build(std::type_identity<Bomberman>,
                                     int id,
                                     sf::Vector2i position,
                                     std::optional<int> health = std::nullopt);

   private:
    TexturesManager* m_textures_manager;
  };

}  // namespace eape

#endif
