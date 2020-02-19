##
## EPITECH PROJECT, 2019
## my_runner
## File description:
## Makefile
##

NAME	=	testing

CC	=	gcc

RM	=	rm -f

SRCS	=	srcs/main.c \
			srcs/engine/engine.c \
			srcs/engine/mouse_pos.c \
			srcs/stmngr/destroy.c \
			srcs/stmngr/init.c \
			srcs/stmngr/stmngr.c \
			srcs/stmngr/utils.c \
			srcs/scenes/init.c \
			srcs/scenes/menu.c \
			srcs/scenes/game.c

%.o: %.c
			cc -o $@ -c $^ -g -W -Wall -Werror -Wextra

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

LDFLAGS	=	-lm -Llib/my/ -lmy -Iinclude/ -g -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	lib $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

lib:
	cd lib/my/ && make all

clean:
	$(RM) $(OBJS)
	cd lib/my/ && make clean

fclean:	clean
	$(RM) $(NAME)
	cd lib/my/ && make fclean

re:	fclean all

.PHONY:	all lib clean fclean re
