#include "Settings.hpp"
#include <bn_sprite_items_game.h>
#include <bn_sprite_text_generator.h>

Settings::Settings(bn::sprite_text_generator &small_text_generator)
    : m_game_sprite(bn::sprite_items::game.create_sprite(0, 0))
{
}

[[nodiscard]] bn::optional<scene_type> Settings::update() { return {}; }
