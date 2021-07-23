# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keulee <keulee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 18:18:39 by keulee            #+#    #+#              #
#    Updated: 2021/07/18 23:01:10 by keulee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/push_swap.c srcs/p01_init.c srcs/p01_utiles.c srcs/p01_list.c \
		srcs/p01_print_list.c srcs/p01_sort_a_to_b.c srcs/p01_create_stack.c \
		srcs/p01_free.c srcs/p01_get_max_min.c srcs/p01_stack_size_three.c \
		srcs/p01_stack_size_five.c srcs/p01_stack_size_two.c srcs/p01_stack_sorted.c \
		srcs/p01_pivot.c

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lft

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
