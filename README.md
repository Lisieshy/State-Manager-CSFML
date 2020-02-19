# State Manager

## Description

Small scene handler made in C for my graphical projects in CSFML at Epitech.\
It's not supposed to be perfect, but it does the work!

**Warning !**\
There are still a lot of bugs, you might have to change the code for yourself and get your hands dirty.

### Usage
***The project contains all the code to open a window and 2 basic scenes.***
- You normally only need to add/remove scenes in the srcs/scenes/ directory, don't forget to initialize them in srcs/scenes/init.c!
- Don't hesitate to change the main() function for your own liking.
- Only change main_game_loop() if you know what you're doing !

### It's in development, don't forget it.
I am not near a profesionnal developer, there can be, and already are, mistakes in the code. If you find any you can always notify me about it, I'll do my best.

#### Known bugs
- stmngr_pop() crashes the program when called in a size 1 pile.
- You should never call stmngr_free() anywhere in the program. To quit everything you should close the window using the sfRenderWindow_close() function.
