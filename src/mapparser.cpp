#include "mapparser.hpp"

#include <fstream>
#include <iostream>

#include "unitsfactory.hpp"

namespace eape {

  class Incrementer {
   public:
    Incrementer() = default;
    Incrementer(int initial_value) : m_x(initial_value) {
    }

    constexpr int peek() const {
      return m_x;
    }

    constexpr operator int() {
      return m_x++;
    }

   private:
    int m_x{};
  };

  MapParser::MapParser(const std::string& path) : m_map_path(path) {
  }

  MapParsedEntities MapParser::parse_map(
    TexturesManager& textures_manager) const {
    Incrementer incremented_id;

    UnitsFactory units_factory(&textures_manager);
    Map map;
    std::vector<std::shared_ptr<Unit>> lhs_units;
    std::vector<std::shared_ptr<Unit>> rhs_units;

    std::ifstream map_stream(m_map_path);
    std::string map_row;

    if (!map_stream.is_open()) {
      std::cerr << "Could not open map file!" << std::endl;
      return {};
    }

    for (auto x = 0; std::getline(map_stream, map_row); ++x) {
      map.add_row(map_row.size());

      for (auto y = 0; auto tile_char : map_row) {
        switch (tile_char) {
          default:
            [[fallthrough]];
          case '.': {
            map[x][y] = Tile::Floor;
            break;
          }
          case '=': {
            map[x][y] = Tile::Water;
            break;
          }
          case '#': {
            map[x][y] = Tile::Wall;
            break;
          }
          case 'a':
            [[fallthrough]];
          case 'b': {
            lhs_units.push_back(units_factory.build<Knight>(
              incremented_id, sf::Vector2i{ y, x }));
            break;
          }
          case 'c':
            [[fallthrough]];
          case 'd': {
            lhs_units.push_back(units_factory.build<Archer>(
              incremented_id, sf::Vector2i{ y, x }));
            break;
          }
          case 'e':
            [[fallthrough]];
          case 'f': {
            lhs_units.push_back(units_factory.build<Bomberman>(
              incremented_id, sf::Vector2i{ y, x }));
            break;
          }
          case 'g':
            [[fallthrough]];
          case 'h': {
            rhs_units.push_back(units_factory.build<Knight>(
              incremented_id, sf::Vector2i{ y, x }));
            break;
          }
          case 'i':
            [[fallthrough]];
          case 'j': {
            rhs_units.push_back(units_factory.build<Archer>(
              incremented_id, sf::Vector2i{ y, x }));
            break;
          }
          case 'k':
            [[fallthrough]];
          case 'l': {
            rhs_units.push_back(units_factory.build<Bomberman>(
              incremented_id, sf::Vector2i{ y, x }));
            break;
          }
        }
        ++y;
      }
    }
    return { std::move(map), { std::move(lhs_units), std::move(rhs_units) } };
  }

}  // namespace eape
