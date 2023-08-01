NAME = push_swap
LIBRARY = push_swap.h
CFLAGS= -Wall -Wextra -Werror
CC = cc

SRC = push_swap.c argv_cleaner.c utils.c

OBJS = $(SRC:.c=.o)

%.o: %.c $(LIBRARY) Makefile
	$(MAKE) -C /Users/alcaball/libft_gh
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	ar -crs $(NAME) $(OBJS) #solo incluye los OBJS de push_swap, inlcuir .o de libft

clean:
	rm -f $(OBJS) $(BONUSOBJS) 

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus