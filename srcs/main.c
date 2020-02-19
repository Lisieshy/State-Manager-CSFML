/*
** EPITECH PROJECT, 2019
** Template
** File description:
** Main
*/

#include "../include/engine.h"

int main_game_loop(engine_t en)
{
    if (engine_init(&en) == -1) {
        engine_free(&en);
        return (84);
    }
    init_states(&en);
    stmngr_push(&en.manager, &en.graphics.menu.state, &en);
    while (sfRenderWindow_isOpen(en.graphics.window)) {
        get_mouse_pos(&en);
        en.dt = sfClock_restart(en.clock);
        en.deltatime = sfTime_asSeconds(en.dt);
        while (sfRenderWindow_pollEvent(en.graphics.window, &en.event)) {
            if (en.event.type == sfEvtClosed)
                sfRenderWindow_close(en.graphics.window);
            stmngr_event(&en.manager, &en);
        }
        stmngr_update(&en.manager, &en);
        stmngr_draw(&en.manager, &en);
    }
    engine_free(&en);
    return (0);
}

int main(int argc, char **argv)
{
    engine_t engine = { 0 };

    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0) {
            // add helper function here //
            return (0);
        } else {
            return (main_game_loop(engine));
        }
    } else {
        return (main_game_loop(engine));
    }
    return (0);
}
