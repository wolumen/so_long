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

OBJ		=	$(SRC:%.c=$O%.o)

O		=	obj/

libft	= 	libft.a
libmlx	=	libmlx.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

MLX_FLAGS =	-lm -lz -Lmlx -lmlx -framework OpenGL -framework AppKit

LEAKS	= 	leaks --atExit  -- 

INC		=	-Imlx

ARG1	=	./maps/map1.ber
ARG2	=	./maps/map2.ber
ARG3	=	./maps/map3.ber


all: $(NAME)

$(OBJ): $O%.o: %.c
	@mkdir -p $O
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):  $(libft) $(libmlx) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(INC) $(libft) $(libmlx) $(MLX_FLAGS)

libft.a:
	$(MAKE) bonus -sC ./libft
	cp ./libft/libft.a ./

libmlx.a:
	$(MAKE) -sC ./mlx
	cp ./mlx/libmlx.a ./

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)
	rm -rf $O

fclean: clean
	rm -f $(NAME) $(libft) $(libmlx)

re: fclean all

map1: all
	./$(NAME) $(ARG1)
	
map2: all
	./$(NAME) $(ARG2)

map3: all
	./$(NAME) $(ARG3)

memcheck1: all
	$(LEAKS) ./$(NAME) $(ARG1)

norminette:
	norminette *.c so_long.h