# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:30:01 by smischni          #+#    #+#              #
#    Updated: 2022/06/17 14:56:23 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c \
				input_validation.c \
				utils.c \
				colors.c \
				events.c \
				mandelbrot.c \
				julia.c \
				burning_ship.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g


NAME		=	fractol
LIBFT		=	libft/libft.a
LIBFT_PATH	=	libft/
MLX			=	../mlx/libmlx.a
MLX_PATH	=	../mlx/

all:		$(NAME)

$(NAME):	libft mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) \
	-L/usr/X11/lib/ -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make -C $(LIBFT_PATH)

mlx:
	@make -C $(MLX_PATH)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make clean -C $(LIBFT_PATH)

fclean:		clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)

re:			fclean all

.PHONY:		all clean fclean re libft mlx
