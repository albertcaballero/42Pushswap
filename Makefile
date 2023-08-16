NAME = push_swap
LIBRARY = push_swap.h
CFLAGS= -Wall -Wextra -Werror
CC = cc

GREEN   =   \033[1;92m
RED     =   \033[1;91m
NC      =   \033[0m
YELLOW  =   \033[1;33m

SRC = push_swap.c argv_cleaner.c utils.c sort5.c movements.c

all: makelib $(NAME)

$(NAME): $(LIBRARY) Makefile $(SRC) libft/libft.a
	$(CC) $(CFLAGS) $(SRC) -L./libft -lft -o $(NAME)

makelib:
	$(MAKE) -C ./libft bonus

clean:
	$(MAKE) -C ./libft clean

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

exec:
	@printf "${RED}"
	./push_swap "4 67 3 87 23"
	@printf "${YELLOW}"
	./push_swap 55 5554 89 98 003 -01
	@printf "${GREEN}"
	./push_swap 1 2 3 4 5
	@printf "${NC}"

PRINT_N = $(grep "printf" $(SRC) | wc -l)

forbidden:
	@printf "${RED}"
	@grep "printf" $(SRC)
	@printf "${YELLOW}"
	@grep "//DELETE" $(SRC)
	@printf "${RED}"
	@norminette > /dev/null && printf "$(GREEN)OK\n" || norminette | grep Error
	@printf "${NC}"

.PHONY: all clean fclean re bonus
