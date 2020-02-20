/*
** EPITECH PROJECT, 2020
** Scenes | Menu
** File description:
** Menu functions
*/

#include "../../include/engine.h"

unsigned int init_menu(void)
{
    my_printf("state 1 created\n");
    return (0);
}

unsigned int update_menu(engine_t *en)
{
    en->deltatime = sfClock_getElapsedTime(\
        en->clock).microseconds / 1000000.0;
    if (en->deltatime > 1) {
        my_printf("1 second has passed...\n");
        sfClock_restart(en->clock);
    }
    return (0);
}

unsigned int event_menu(engine_t *en)
{
    if (en->event.type == sfEvtMouseButtonPressed) {
        my_printf("Mouse button pressed in the menu\n");
    }
    if (en->event.type == sfEvtKeyPressed) {
        if (en->event.key.code == sfKeyG) {
            stmngr_push(&en->manager, &en->graphics.game.state, en);
        }
        if (en->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(en->graphics.window);
        }
    }
    return (0);
}

unsigned int draw_menu(engine_t *en)
{
    sfRenderWindow_clear(en->graphics.window, sfBlue);
    sfRenderWindow_display(en->graphics.window);
    return (0);
}

unsigned int destroy_menu(void)
{
    my_printf("state 1 destroyed\n");
    return (0);
}
