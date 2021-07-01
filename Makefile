##
## EPITECH PROJECT, 2021
## B-PSU-200-REN-2-1-bsmysokoban-audrey.amar
## File description:
## Makefile
##

SRC    =    src/my_malloc.c	\
			src/my_strncpy.c	\
			src/my_putchar.c    \
			src/my_putstr.c	\
			src/my_put_nbr.c	\
			src/my_strlen.c 	\
			src/my_getnbr.c     \
			src/my_generate_map.c	\
			src/my_matchstick.c	\
			src/my_ia.c		\
			src/my_change.c		\
			src/error.c	\

OBJ    =    $(SRC:.c=.o)

NAME    =    matchstick

CFLAGS    =    -Wall -Wextra -W -I includes

all:    $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)

re:    fclean all