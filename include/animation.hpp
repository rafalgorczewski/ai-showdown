#ifndef EAPE_ANIMATION_HPP
#define EAPE_ANIMATION_HPP

#include <SFML/Graphics.hpp>

namespace eape {

  enum class AnimationMode { Normal, Immediate };

  class Animation {
   public:
    Animation() = default;
    Animation(sf::Vector2i tile_starting_position,
              sf::Vector2i tile_size,
              int tile_count);

   public:
    sf::IntRect get_current_tile() const;
    void change_tile_to_next();
    void reset_animation();
    int tiles_left_for_full_sequence() const;

   private:
    sf::Vector2i m_tile_starting_position{};
    sf::Vector2i m_tile_size{};
    int m_tile_count{};

    int m_current_tile_number{};
  };

}  // namespace eape

#endif  // EAPE_ANIMATION_HPP
