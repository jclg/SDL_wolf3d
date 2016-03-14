##
## Makefile for makefile in /home/le-gof_j
## 
## Made by jean-charles le-goff
## Login   <le-gof_j@epitech.net>
## 
## Started on  Fri Oct 17 08:48:37 2008 jean-charles le-goff
##

CC_FreeBSD	= cc

CC_		= cc

CC_sun	= /usr/sfw/bin/gcc

NAME	= wolf3d

SRC	= ./main.c\
		key.c\
		raycasting.c\
		draw.c\
		get_map.c\
		get_next_line.c

OBJ	= $(SRC:.c=.o)

LIB	= -Lliblinux -lSDL -lSDL_image -lm

CFLAGS	= -W -Wall -pedantic -Iinclude

RM	= rm -f

all	: $(NAME)

$(NAME)	: $(OBJ)
	cc -o $(NAME) $(OBJ) $(LIB)
##$(CC_$(HOSTTYPE)) -o $(NAME) $(OBJ) $(LIB)

clean	:
	$(RM) $(OBJ) *~ \#*

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

love	:
	echo ". . . not war"