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

MLX_FLAGS =	-lm -lz -framework OpenGL -framework AppKit

VAL		= 	leaks --atExit  -- 


ARG1	=	./maps/map1.ber
ARG2	=	./maps/map2.ber
ARG3	=	./maps/map3.ber


all: $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME):  $(libft) $(libmlx) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(libft) $(libmlx) $(MLX_FLAGS)

libft.a:
	$(MAKE) bonus -sC ./libft
	cp ./libft/libft.a ./

libmlx.a:
	$(MAKE) -sC ./mlx
	cp ./mlx/libmlx.a ./

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(libft) $(libmlx)

re: fclean all

test1: all
	./$(NAME) $(ARG1)
	
test2: all
	./$(NAME) $(ARG2)

test3: all
	./$(NAME) $(ARG3)

memcheck1: all
	$(VAL) ./$(NAME) $(ARG1)
	
memcheck2: all
	$(VAL) ./$(NAME) $(ARG2)


norminette:
	norminette *.c so_long.h