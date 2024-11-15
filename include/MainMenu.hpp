#ifndef STARDEW_BOY_MAINMENU_HPP
#define STARDEW_BOY_MAINMENU_HPP

#include "Scene.hpp"
#include "bn_vector.h"
#include <bn_optional.h>
#include <bn_sprite_actions.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_text_generator.h>

class MainMenu : public Scene
{
  public:
    explicit MainMenu(bn::sprite_text_generator &small_text_generator);
    MainMenu(const MainMenu &other) = delete;

    MainMenu &operator=(const MainMenu &other) = delete;

    [[nodiscard]] bn::optional<scene_type> update() final;

  private:
    void update_cursor();

    bn::sprite_ptr m_cursor_sprite;
    bn::optional<bn::sprite_move_to_action> m_cursor_move;
    bn::vector<bn::sprite_ptr, 4> m_play_text{};
    bn::vector<bn::sprite_ptr, 8> m_settings_text{};
    bn::vector<bn::sprite_ptr, 7> m_credits_text{};
    short m_menu_index = 0;
};

#endif // !STARDEW_BOY_MAINMENU_HPP
