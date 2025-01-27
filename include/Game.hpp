#ifndef STARDEW_BOY_GAME_HPP
#define STARDEW_BOY_GAME_HPP

#include "Scene.hpp"
#include <bn_optional.h>
#include <bn_point.h>
#include <bn_sprite_actions.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_text_generator.h>
#include <bn_timer.h>

class Game : public Scene
{
  public:
    explicit Game(bn::sprite_text_generator &small_text_generator);
    Game(const Game &other) = delete;

    Game &operator=(const Game &other) = delete;

    [[nodiscard]] bn::optional<scene_type> update() final;

  private:
    void update_player();

    bn::sprite_ptr m_game_sprite;
    bn::sprite_ptr m_player_sprite;
    bn::point m_velocity;
    bn::timer m_timer;
};

#endif // !STARDEW_BOY_GAME_HPP
