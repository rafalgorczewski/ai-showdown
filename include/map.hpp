#ifndef EAPE_MAP_HPP
#define EAPE_MAP_HPP

#include <cstddef>
#include <string>
#include <vector>

namespace eape {

  enum class Tile { Floor, Water, Wall };

  class Map {
   public:
    std::vector<Tile>& operator[](std::size_t index) &;
    const std::vector<Tile>& operator[](std::size_t index) const&;
    const std::vector<Tile>& operator[](std::size_t index) const&& = delete;

    void add_row(std::size_t size);

   private:
    std::vector<std::vector<Tile>> m_tiles;
  };

}  // namespace eape

#endif  // EAPE_MAP_HPP
