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

			
SRC		=	main.c 		\
			deal_key.c			\
			init_map.c			\
			init.c				\
			check_args.c		\
			check_map.c			\
			set_map.c			\
			directions.c		\
			move_dependences.c	\
			exit.c				\
			utils.c

OBJ		=	$(SRC:%.c=%.o)

libft	= 	libft.a
libmlx	=	libmlx.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

MLX_FLAGS =	-lX11 -lXext -lm

VAL			:= valgrind
VAL_FLAGS	:= --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt

ARG1	=	./maps/map_1.ber
ARG2	=	./maps/map_2.ber
ARG3	=	./maps/map_3.ber



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
	rm -f ./libft/$(libft)

re: fclean all

test1: all
	./$(NAME) $(ARG1)

test2: all
	./$(NAME) $(ARG2)

test3: all
	./$(NAME) $(ARG3)

memcheck1: all
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARG1)

memcheck2: all
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARG2)