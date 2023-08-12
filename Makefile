NAME = push_swap
LIBRARY = push_swap.h
CFLAGS= -Wall -Wextra -Werror
CC = cc

SRC = push_swap.c argv_cleaner.c utils.c sort5.c

$(NAME): $(LIBRARY) Makefile
	$(MAKE) -C ./libft bonus
	$(CC) $(CFLAGS) $(SRC) -L./libft -lft -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C ./libft clean

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus