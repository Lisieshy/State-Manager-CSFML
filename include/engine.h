/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** engine.h
*/

#ifndef H_ENGINE
#define H_ENGINE

#include <SFML/Graphics.h>
#include <unistd.h>
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct engine_s;

typedef unsigned int (*fptr_f)(struct engine_s *);

typedef struct state_s {
    fptr_f init;
    fptr_f update;
    fptr_f draw;
    fptr_f event;
    fptr_f destroy;
} state_t;

typedef struct st_manager_s {
    state_t **stack;
    int size;
    int top;
} st_manager_t;

typedef struct game_objects_s {
    sfVector2f position;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
} game_objects_t;

typedef struct window_s {
    char *title;
    int width;
    int height;
    int framerate;
} window_t;

typedef struct scene_s {
    game_objects_t *objects;
    state_t state;
} scene_t;

typedef struct graphics_s {
    sfRenderWindow *window;
    window_t winvar;
    scene_t menu;
    scene_t game;
} graphics_t;

typedef struct engine_s {
    graphics_t graphics;
    st_manager_t manager;
    sfEvent event;
    sfClock *clock;
    sfTime dt;
    sfVector2i mouse_pos_window;
    sfVector2i mouse_pos_screen;
    float deltatime;
} engine_t;

int engine_init(engine_t *engine);
int engine_free(engine_t *engine);

int graphics_init(graphics_t *graphics);
int graphics_free(graphics_t *graphics);

int stmngr_init(st_manager_t *manager);
int stmngr_free(st_manager_t *manager, engine_t *engine);
int stmngr_push(st_manager_t *manager, state_t *state, engine_t *engine);
int stmngr_pop(st_manager_t *manager, engine_t *engine);
int stmngr_update(st_manager_t *manager, engine_t *engine);
int stmngr_event(st_manager_t *manager, engine_t *engine);
int stmngr_draw(st_manager_t *manager, engine_t  *engine);
int stmngr_scale(st_manager_t *manager);
state_t *stmngr_top(st_manager_t *manager);

void init_states(engine_t *engine);
int get_mouse_pos(engine_t *engine);

#endif