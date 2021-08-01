NAME = checker

SRCS = ./srcs/checker.c \
		./srcs/get_next_line.c \
		./srcs/op_push.c \
		./srcs/op_reverse.c \
		./srcs/op_rotate.c \
		./srcs/op_swap.c \
		./srcs/init.c \
		./srcs/create_stack.c \
		./srcs/free.c

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lft

$(LIBFT):
	$(MAKE) -C ../libft
	mv ../libft/$(LIBFT) .

clean:
	$(MAKE) -C ../libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ../libft fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all