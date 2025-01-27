#include "Game.hpp"
#include "bn_keypad.h"
#include "bn_sprite_items_cursor.h"
#include <bn_sprite_items_game.h>
#include <bn_sprite_text_generator.h>
#include <cmath>

Game::Game(bn::sprite_text_generator &small_text_generator)
    : m_game_sprite(bn::sprite_items::game.create_sprite(0, 0)),
      m_player_sprite(bn::sprite_items::cursor.create_sprite(0, 0))
{
}

[[nodiscard]] bn::optional<scene_type> Game::update()
{
    update_player();
    return {};
}

void Game::update_player()
{
    if (bn::keypad::up_pressed()) {
        // TODO: face up
    } else if (bn::keypad::down_pressed()) {
        // TODO: face down
    } else if (bn::keypad::left_pressed()) {
        // TODO: face left
    } else if (bn::keypad::right_pressed()) {
        // TODO: face right
    }

    if (bn::keypad::up_held()) {
        // TODO: velocity up
        if (m_velocity.y() > -100)
            m_velocity.set_y(m_velocity.y() - 10);
    }
    if (bn::keypad::down_held()) {
        // TODO: velocity down
        if (m_velocity.y() < 100)
            m_velocity.set_y(m_velocity.y() + 10);
    }
    if (bn::keypad::left_held()) {
        // TODO: velocity left
        if (m_velocity.x() > -100)
            m_velocity.set_x(m_velocity.x() - 10);
    }
    if (bn::keypad::right_held()) {
        // TODO: velocity right
        if (m_velocity.x() < 100)
            m_velocity.set_x(m_velocity.x() + 10);
    }
    m_velocity.set_x(std::round(m_velocity.x() * 0.9));
    m_velocity.set_y(std::round(m_velocity.y() * 0.9));
    auto elapsed = m_timer.elapsed_ticks();
    if (m_player_sprite.x() + m_velocity.x() / 10 * elapsed / 1000 > 120 ||
        m_player_sprite.x() + m_velocity.x() / 10 * elapsed / 1000 < -120) {
        m_velocity.set_x(0);
    }

    if (m_player_sprite.y() + m_velocity.y() / 10 * elapsed / 1000 > 80 ||
        m_player_sprite.y() + m_velocity.y() / 10 * elapsed / 1000 < -80) {
        m_velocity.set_y(0);
    }
    m_player_sprite.set_position(m_player_sprite.x() + m_velocity.x() * elapsed / 1000,
                                 m_player_sprite.x() + m_velocity.y() * elapsed / 1000);
    m_timer.restart();
}
