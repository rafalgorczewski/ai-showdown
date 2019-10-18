#ifndef EAPE_UNIT_HPP
#define EAPE_UNIT_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.hpp"
namespace eape {

  class Unit : public Drawable {
   public:
    Unit(int id,
         const SpriteController& sprite_controller,
         sf::Vector2i position = {});
    virtual ~Unit() = default;

    virtual bool can_attack(const Map& map, Unit& enemy) const = 0;
    virtual void attack(Unit& enemy) const = 0;

    int get_id() const;

    sf::Vector2i get_position() const;
    void set_position(sf::Vector2i new_position);

    void move_by(sf::Vector2i offset);

   private:
    int m_id;
    sf::Vector2i m_position;
  };

}  // namespace eape

#endif  // EAPE_UNIT_HPP
