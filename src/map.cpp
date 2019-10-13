#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

#include "map.hpp"

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

  std::vector<sf::Sprite>& Map::get_sprites(
    TexturesManager& textures_manager) & {
    if (!m_sprites) {
      generate_sprites(textures_manager);
    }
    return *m_sprites;
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
