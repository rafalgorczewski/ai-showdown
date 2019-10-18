#ifndef EAPE_UNIT_HPP
#define EAPE_UNIT_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.hpp"
#include "map.hpp"

namespace eape {

  class Unit : public Drawable {
   public:
    Unit(int id,
         const SpriteController& sprite_controller,
         int health = 3,
         sf::Vector2i position = {});
    virtual ~Unit() = default;

    virtual bool can_attack(const Map& map, Unit& enemy) const = 0;
    virtual void attack(Unit& enemy) = 0;
    void receive_damage(int damage);
    virtual void die();
    void move(sf::Vector2i new_position);
    void move_by(sf::Vector2i offset);

    int get_id() const;
    sf::Vector2i get_position() const;

    bool is_dead() const;

   private:
    int m_id;
    int m_health;
    sf::Vector2i m_position;
  };

}  // namespace eape

#endif  // EAPE_UNIT_HPP
