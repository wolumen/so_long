# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 13:00:21 by jpreissn          #+#    #+#              #
#    Updated: 2021/12/14 13:00:21 by jpreissn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

			
SRC		=	max_the_game.c \
			deal_key.c \
			init_map.c \
			init_img.c \
			set_map.c \
			move_dependences.c \
			exit.c

OBJ		=	$(SRC:%.c=%.o)

libft	= 	libft.a
libmlx	=	libmlx.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

MLX_FLAGS =	-lX11 -lXext -lm

VAL			:= valgrind
VAL_FLAGS	:= --leak-check=full --show-leak-kinds=all --track-origins=yes
--log-file=valgrind-out.txt



all: $(NAME)

$(NAME):  $(libft) $(libmlx) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(libft) $(libmlx) $(MLX_FLAGS)


libft.a:
	$(MAKE) bonus -sC ./libft
	cp ./libft/libft.a ./

libmlx.a:
	$(MAKE) -sC ./mlx-linux
	cp ./mlx-linux/libmlx.a ./


clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(libft) $(libmlx)

re: fclean all

test1: all
	./$(NAME) ./maps/map1.ber

test2: all
	./$(NAME) ./maps/map2.ber

test3: all
	./$(NAME) ./maps/map_large.ber

memcheck1: all
	$(VAL) $(VAL_FLAGS) ./$(NAME) ./maps/map1.ber

memcheck2: all
	$(VAL) $(VAL_FLAGS) ./$(NAME) ./maps/map2.ber