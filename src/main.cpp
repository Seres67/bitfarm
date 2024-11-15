#include "MainMenu.hpp"
#include "Scene.hpp"
#include "bf_small_sprite_font.h"
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

    while (true) {
        auto next_scene = scene->update();
        bn::core::update();
    }
}
