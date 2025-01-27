#include "Game.hpp"
#include "MainMenu.hpp"
#include "SceneType.hpp"
#include "Settings.hpp"
#include "SmallSpriteFont.h"
#include <bn_core.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_text_generator.h>
#include <bn_unique_ptr.h>
#include <bn_vector.h>
#include <compare>

// NOTE: screen is 240*160 so top left is -120;-80
// -74 is small font minimum height
int main()
{
    bn::core::init();
    bn::sprite_text_generator small_text_generator(small_sprite_font);
    small_text_generator.set_bg_priority(1);
    bn::unique_ptr<Scene> scene(new MainMenu(small_text_generator));
    scene_type current_scene = scene_type::MAIN_MENU;

    while (true) {
        auto next_scene = scene->update();
        if (next_scene) {
            if (current_scene != next_scene) {
                switch (*next_scene) {
                case scene_type::GAME:
                    scene.reset(new Game(small_text_generator));
                    break;
                case scene_type::MAIN_MENU:
                    scene.reset(new MainMenu(small_text_generator));
                    break;
                case scene_type::SETTINGS:
                    scene.reset(new Settings(small_text_generator));
                default:
                    break;
                }
            }
        }
        bn::core::update();
    }
}
