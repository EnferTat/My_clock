##
## makefile for my_watch in /Users/BQN_T/Documents/cours/projet/perso/Montre binaire
##
## Made by Thibaut Bourquin
## Login   <bourqu_t@etna-alternance.net>
##
## Started on  Wed Sep  25 22:07:19 2013 Thibaut Bourquin
## Last update Wed Sep  25 22:07:19 2013 Thibaut Bourquin
##

CC		=	gcc

NAME	=	my_watch

SRC		=	main.c

OBJ		=	$(SRC:%.c=%.o)

LM		=	-L. -lm

CFLAGS 	+=	-W -Werror -Wall

LDFLAGS	+= `sdl-config --cflags --libs` -lSDL -lm

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(LM) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
			$(RM)	$(OBJ)

fclean:		clean
			$(RM)	$(NAME)

re:			fclean all
