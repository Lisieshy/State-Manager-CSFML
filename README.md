# State Manager

## Attention aux Epitech
Copiez pas ce code bêtement, sinon le -42 va vous faire mal!

## Description

Small scene handler made in C for my graphical projects in CSFML at Epitech.\
It's not supposed to be perfect, but it does the work!\

**Warning !**\
There are still a lot of bugs, you might have to change the code for yourself and get your hands dirty.

### Usage
***The project contains all the code to open a window and 2 basic scenes.***
***Also contains all of the basics of a game object and a scene struct. The scene struct contains the state struct.***
- The state_t struct is, simply put, a struct of 5 function pointers. There is, in order, init, update, event, draw and destroy functions. All are needed for the manager to work. They all take an engine_t * argument or a void argument. See in the sources how they are initialized.
- The pile is where all your states go. The pile works by simply addind and removing scenes from it. The first scene added will be the last to be destroyed. When you add a scene to the pile, the manager will switch everything to show this scene on the screen. The state on top of the pile will always be prioritized. Order is very important! You can only add/remove scenes, not skip between them!
- You normally only need to add/remove scenes in the srcs/scenes/ directory, don't forget to initialize them in srcs/scenes/init.c!
- Use stmngr_push() to add a scene. It will add the scene passed as a parameter to the pile.
- Use stmngr_pop() to remove a scene. It will delete itself from the pile.
- Check engine.h for the prototypes of the functions and see what arguments they are taking.
- Don't hesitate to change the main() function for your own liking.
- Only change main_game_loop() if you know what you're doing !

### It's in development, don't forget it.
I am not near a profesionnal developer, there can be, and already are, mistakes in the code. If you find any you can always notify me about it, I'll do my best to fix them.

#### Known bugs
- stmngr_pop() crashes the program when called in a single scene program.
- You should never call stmngr_free() anywhere in the program. To quit everything you should close the window using the sfRenderWindow_close() function.
