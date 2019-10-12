#include "texturesmanager.hpp"

namespace eape {

  void TexturesManager::load() {
    // TODO
  }

  sf::Texture& TexturesManager::operator[](const std::string& name) & {
    return m_textures[name];
  }

}
