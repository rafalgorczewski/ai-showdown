#include "texturesmanager.hpp"

namespace eape {

  void TexturesManager::load() {
    m_textures["floor"].loadFromFile("res/floor.png");
    m_textures["water"].loadFromFile("res/water.png");
    m_textures["wall"].loadFromFile("res/wall.png");

    m_textures["knight"].loadFromFile("res/knight.png");
    m_textures["archer"].loadFromFile("res/archer.png");
    m_textures["bomberman"].loadFromFile("res/bomberman.png");
  }

  sf::Texture& TexturesManager::operator[](const std::string& name) & {
    return m_textures[name];
  }

}  // namespace eape
