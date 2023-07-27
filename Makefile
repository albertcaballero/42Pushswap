FILE = push_swap
LIBRARY = push_swap.h
CFLAGS= -Wall -Wextra -Werror
CC = cc

SRC = push_swap.c 

OBJS = $(SRC:.c=.o)

%.o: %.c $(LIBRARY) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	ar -crs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUSOBJS) 

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus