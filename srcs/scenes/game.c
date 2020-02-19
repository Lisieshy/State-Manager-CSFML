/*
** EPITECH PROJECT, 2020
** Scenes | Menu
** File description:
** Menu functions
*/

#include "../../include/engine.h"

unsigned int init_game(void)
{
    my_printf("state 2 created\n");
    return (0);
}

unsigned int update_game(engine_t *en)
{
    if (en->deltatime > 1) {
        my_printf("1 second has passed...\n");
    }
    return (0);
}

unsigned int event_game(engine_t *en)
{
    if (en->event.type == sfEvtMouseButtonPressed) {
        my_printf("Mouse button pressed\n");
        
    }
    if (en->event.type == sfEvtKeyPressed) {
        if (en->event.key.code == sfKeyEscape) {
            stmngr_pop(&en->manager, en);
        }
    }
    return (0);
}

unsigned int draw_game(engine_t *en)
{
    sfRenderWindow_clear(en->graphics.window, sfRed);
    sfRenderWindow_display(en->graphics.window);
    return (0);
}

unsigned int destroy_game(void)
{
    my_printf("state 2 destroyed\n");
    return (0);
}