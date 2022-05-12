# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:30:01 by smischni          #+#    #+#              #
#    Updated: 2022/05/12 16:32:06 by smischni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	fractol.c

OBJS		=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror


NAME		=	fractol
LIBFT		=	libft/libft.a
LIBFT_PATH	=	libft/

all:		$(NAME)

$(NAME):	libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make clean -C $(LIBFT_PATH)

fclean:		clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)

re:			fclean all

.PHONY:		all clean fclean re libft
