#include "MainMenu.hpp"
#include "SceneType.hpp"
#include <bn_assert.h>
#include <bn_keypad.h>
#include <bn_log.h>
#include <bn_sprite_items_cursor.h>
#include <bn_sprite_text_generator.h>

MainMenu::MainMenu(bn::sprite_text_generator &small_text_generator)
    : m_cursor_sprite(bn::sprite_items::cursor.create_sprite(0, 0))
{
    m_play_text = small_text_generator.generate<4>(12, -4, "PLAY");
    m_settings_text = small_text_generator.generate<8>(0, 4, "SETTINGS");
    m_credits_text = small_text_generator.generate<7>(3, 12, "CREDITS");
    m_cursor_sprite.set_position(m_settings_text[0].x() - 28, m_play_text[0].y());
}

[[nodiscard]] bn::optional<scene_type> MainMenu::update() { return update_cursor(); }

bn::optional<scene_type> MainMenu::update_cursor()
{
    bn::optional<scene_type> result;
    if (m_cursor_move) {
        /*BN_LOG("duration updates: ", m_cursor_move->duration_updates());*/
        m_cursor_move->update();
        if (m_cursor_move->done()) {
            m_cursor_move.reset();
        }
    } else {
        if (bn::keypad::a_pressed()) {
            if (m_menu_index == 0) { // PLAY
                result = scene_type::GAME;
                // TODO: change scene, run game
            } else if (m_menu_index == 1) { // SETTINGS
                result = scene_type::SETTINGS;
                // TODO: change scene, display settings
            } else if (m_menu_index == 2) { // CREDITS
                result = scene_type::CREDITS;
            }
        } else if (bn::keypad::up_pressed() || bn::keypad::down_pressed()) {
            if (bn::keypad::up_pressed()) {
                if (m_menu_index == 0) {
                    m_menu_index = 2;
                } else {
                    m_menu_index -= 1;
                }
            } else if (bn::keypad::down_pressed()) {
                if (m_menu_index == 2) {
                    m_menu_index = 0;
                } else {
                    m_menu_index += 1;
                }
            }
            switch (m_menu_index) {
            case 0:
                m_cursor_move.emplace(m_cursor_sprite, 3, m_cursor_sprite.x(), m_play_text[0].y());
                break;
            case 1:
                m_cursor_move.emplace(m_cursor_sprite, 3, m_cursor_sprite.x(), m_settings_text[0].y());
                break;
            case 2:
                m_cursor_move.emplace(m_cursor_sprite, 3, m_cursor_sprite.x(), m_credits_text[0].y());
                break;
            default:
                BN_ERROR("Invalid menu index: ", m_menu_index);
                break;
            }
        }
    }
    return result;
}
