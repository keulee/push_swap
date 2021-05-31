# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keulee <keulee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 18:18:39 by keulee            #+#    #+#              #
#    Updated: 2021/05/28 16:40:23 by keulee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.c

SRCS = srcs/push_swap.c

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIB) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C libft
	mv libft/$(LIBFT) .

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
