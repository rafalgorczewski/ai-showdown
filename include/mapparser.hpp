#ifndef EAPE_MAPPARSER_HPP
#define EAPE_MAPPARSER_HPP

#include <memory>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "map.hpp"
#include "texturesmanager.hpp"
#include "unit.hpp"

namespace eape {

  struct MapParsedEntities {
    Map map;
    std::pair<std::vector<std::shared_ptr<Unit>>,
              std::vector<std::shared_ptr<Unit>>>
      units;
  };

  class MapParser {
   public:
    MapParser(const std::string& path);

    MapParsedEntities parse_map(TexturesManager& textures_manager) const;

   private:
    std::string m_map_path;
  };

}  // namespace eape

#endif  // EAPE_MAPPARSER_HPP
