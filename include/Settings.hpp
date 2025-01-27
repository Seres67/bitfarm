#ifndef STARDEW_BOY_SETTINGS_HPP
#define STARDEW_BOY_SETTINGS_HPP

#include "Scene.hpp"
#include <bn_optional.h>
#include <bn_sprite_actions.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_text_generator.h>
#include <bn_vector.h>

class Settings : public Scene
{
  public:
    explicit Settings(bn::sprite_text_generator &small_text_generator);
    Settings(const Settings &other) = delete;

    Settings &operator=(const Settings &other) = delete;

    [[nodiscard]] bn::optional<scene_type> update() final;

  private:
    bn::sprite_ptr m_game_sprite;
};

#endif // !STARDEW_BOY_SETTINGS_HPP
