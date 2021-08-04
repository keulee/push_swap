# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keulee <keulee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 18:18:39 by keulee            #+#    #+#              #
#    Updated: 2021/08/04 16:40:08 by keulee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

SRCS = srcs/push_swap.c \
		srcs/p01_op_swap.c \
		srcs/p01_op_push.c \
		srcs/p01_op_rotate.c \
		srcs/p01_op_reverse.c \
		srcs/p01_init.c \
		srcs/p01_create_stack.c \
		srcs/p01_sort_start.c \
		srcs/p01_sort_a_to_b.c \
		srcs/p01_exception_a_to_b.c \
		srcs/p01_sort_b_to_a.c \
		srcs/p01_exception_b_to_a.c \
		srcs/p01_free.c \
		srcs/p01_get_max_min.c \
		srcs/p01_pivot.c \
		srcs/p01_stack_size_three.c \
		srcs/p01_stack_size_five.c \
		srcs/p01_stack_size_two.c \
		srcs/p01_stack_sorted.c \
		srcs/p01_print_list.c 

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

bonus: re
	@$(MAKE) fclean -C bonus_checker
	@$(MAKE) -C bonus_checker
	@cp ./bonus_checker/checker ./checker

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lft

$(LIBFT):
	@$(MAKE) -C libft
	@mv libft/$(LIBFT) .

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C bonus_checker clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C libft fclean
	@$(MAKE) -C bonus_checker fclean
	@$(RM) $(NAME) $(LIBFT) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
