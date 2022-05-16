# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:30:01 by smischni          #+#    #+#              #
#    Updated: 2022/05/14 16:12:08 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ggf. anpassen und mlx nicht mit compilen & pushen ##

SRCS		=	fractol.c \
				mandelbrot.c \
				julia.c

OBJS		=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror


NAME		=	fractol
LIBFT		=	libft/libft.a
LIBFT_PATH	=	libft/
MLX			=	mlx/libmlx.a
MLX_PATH	=	mlx/

all:		$(NAME)

$(NAME):	libft mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) \
	-L/usr/X11/lib/ -lXext -lX11 -lm -o $(NAME)

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
