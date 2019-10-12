#ifndef EAPE_SPRITECONTROLLER_HPP
#define EAPE_SPRITECONTROLLER_HPP

#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "animation.hpp"

namespace eape {

  enum class AnimationMode { Normal, Immediate };

  class SpriteController {
   public:
    static constexpr auto DEFAULT_MS_PER_NORMAL_FRAME = 20;
    static constexpr auto DEFAULT_MS_PER_IMMEDIATE_FRAME = 15;

   public:
    SpriteController(const sf::Texture& texture);

   public:
    void add_animation(const std::string& name, const Animation& animation);
    void use_animation(const std::string& name,
                       AnimationMode animation_mode = AnimationMode::Normal,
                       int ms_per_frame = DEFAULT_MS_PER_NORMAL_FRAME);
    void update();

    sf::Sprite& get_sprite() &;
    const sf::Sprite& get_sprite() const&;
    const sf::Sprite& get_sprite() const&& = delete;

   private:
    bool animation_already_exists(const std::string& name) const;
    bool is_normal_animation_set() const;
    bool is_immediate_animation_active() const;
    void reset_previous_normal_animation();
    void select_as_normal_animation(const std::string& name);
    void select_as_immediate_animation(const std::string& name);
    void reset_clock();
    void update_immediate_animation();
    bool are_immediate_frames_left();
    void proceed_immediate_animation();
    void end_immediate_animation();
    void update_normal_animation();
    void proceed_normal_animation();
    int elapsed_time() const;

   private:
    sf::Sprite m_sprite;

    std::unordered_map<std::string, Animation> m_animations;
    std::string m_normal_animation;
    std::string m_immediate_animation;

    int m_ms_per_normal_frame = DEFAULT_MS_PER_NORMAL_FRAME;
    int m_ms_per_immediate_frame = DEFAULT_MS_PER_IMMEDIATE_FRAME;
    sf::Clock m_animation_clock;
  };

}  // namespace eape

#endif  // EAPE_SPRITECONTROLLER_HPP
