#include "map.hpp"

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

namespace eape {

  std::vector<Tile>& Map::operator[](std::size_t x) & {
    return m_tiles[x];
  }

  const std::vector<Tile>& Map::operator[](std::size_t x) const& {
    return m_tiles[x];
  }

  void Map::add_row(std::size_t size) {
    m_tiles.emplace_back(size);
  }

  bool Map::is_tile_passable(sf::Vector2i position) const {
    return m_tiles[position.x][position.y] == Tile::Floor;
  }

  std::vector<sf::Sprite>& Map::get_sprites(
    TexturesManager& textures_manager) & {
    if (!m_sprites) {
      generate_sprites(textures_manager);
    }
    return *m_sprites;
  }

  sf::Vector2i Map::get_size() const {
    if (m_tiles.empty()) {
      return {};
    }
    return { m_tiles.size(), m_tiles.front().size() };
  }

  eap::Map Map::serialize_partially() const {
    eap::Map map_proto;

    map_proto.mutable_size()->set_x(get_size().x);
    map_proto.mutable_size()->set_y(get_size().y);

    for (std::size_t x = 0; x < get_size().x; ++x) {
      for (std::size_t y = 0; y < get_size().y; ++y) {
        auto const tile_proto = map_proto.add_tiles();
        switch (m_tiles[x][y]) {
          case Tile::Floor: {
            tile_proto->set_type(eap::Tile_Type::Tile_Type_FLOOR);
            break;
          }
          case Tile::Water: {
            tile_proto->set_type(eap::Tile_Type::Tile_Type_WATER);
            break;
          }
          case Tile::Wall: {
            tile_proto->set_type(eap::Tile_Type::Tile_Type_WALL);
            break;
          }
        }
        tile_proto->mutable_position()->set_x(x);
        tile_proto->mutable_position()->set_x(y);
      }
    }

    return map_proto;
  }

  void Map::generate_sprites(TexturesManager& textures_manager) {
    m_sprites.emplace();
    for (std::size_t y = 0; const auto& row : m_tiles) {
      for (std::size_t x = 0; const auto& tile : row) {
        sf::Sprite sprite;
        switch (tile) {
          default:
            [[fallthrough]];
          case Tile::Floor: {
            sprite.setTexture(textures_manager["floor"]);
            break;
          }
          case Tile::Water: {
            sprite.setTexture(textures_manager["water"]);
            break;
          }
          case Tile::Wall: {
            sprite.setTexture(textures_manager["wall"]);
            break;
          }
        }
        sprite.setPosition({ x * sprite.getTexture()->getSize().x,
                             y * sprite.getTexture()->getSize().y });

        m_sprites->push_back(std::move(sprite));
        ++x;
      }
      ++y;
    }
  }

}  // namespace eape
