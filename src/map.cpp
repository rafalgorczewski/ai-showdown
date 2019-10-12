#include <fstream>
#include <iostream>
#include <vector>

#include "map.hpp"

namespace eape {

  std::vector<Tile>& Map::operator[](std::size_t index) & {
    return m_tiles[index];
  }

  const std::vector<Tile>& Map::operator[](std::size_t index) const& {
    return m_tiles[index];
  }

  void Map::add_row(std::size_t size) {
    m_tiles.emplace_back(size);
  }

}  // namespace eape
