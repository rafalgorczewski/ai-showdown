#ifndef EAPE_WINDOW_HPP
#define EAPE_WINDOW_HPP

#include <string>

#include <SFML/Graphics.hpp>

namespace eape {

  class Window : public sf::RenderWindow {
   public:
    Window(const sf::Vector2u& size, const std::string& title);

    void handleEvents();

   private:
    static constexpr auto FRAMERATE_LIMIT = 60;
  };

}  // namespace eape

#endif  // EAPE_WINDOW_HPP
