NAME = push_swap
LIBRARY = push_swap.h
CFLAGS= -Wall -Wextra -Werror
CC = cc

SRC = push_swap.c argv_cleaner.c utils.c sort5.c

OBJS = $(SRC:.c=.o)

%.o: %.c $(LIBRARY) Makefile
	$(MAKE) -C ./libft bonus
	$(CC) $(CFLAGS) -c $< -o $@ -L./libft -lft
	10/08/2023 ME HE QUEDDADO AQUI YA CASI ESTA PERO NO DEL TODO

all: $(NAME)

$(NAME):$(OBJS)

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus