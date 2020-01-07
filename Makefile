# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 10:28:40 by ael-imra          #+#    #+#              #
#    Updated: 2019/12/25 10:28:44 by ael-imra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = gcc

SRC = main.c menu_usage.c lib_func.c func.c press.c draw_utils.c mouse_press.c

OBJS = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
