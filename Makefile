# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpatoux <rpatoux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 21:49:16 by rpatoux           #+#    #+#              #
#    Updated: 2017/06/13 19:36:16 by rpatoux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3d

RM	= rm -rf

LIB = -L ./libft/ -lft -L ./minilibx_macos/ -lft

HEADER = -I ./includes

CC = gcc -Werror -Wextra -Wall -I./includes

MLX = -lmlx -framework OpenGL -framework AppKit 

SRCS = 	srcs/main.c \
		srcs/parse.c \
		srcs/event.c \
		srcs/moove.c \
		srcs/moove_two.c \
		srcs/raycasting.c \
		srcs/raycasting_two.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(MLX) -o $(NAME) $(OBJS) $(LIB) $(HEADER)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft/
	make clean -C minilibx_macos/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all
