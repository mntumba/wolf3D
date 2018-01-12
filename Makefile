# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mntumba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 21:57:58 by mntumba           #+#    #+#              #
#    Updated: 2018/01/09 15:41:34 by mntumba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = display.c key_hook.c main.c\
	  parser.c ray_calc.c\

OBJ = $(SRC:.c=.o)

LIB = -L minilibx_macos -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ)
		gcc -Wall -Wextra -Werror -g $(LIB) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
