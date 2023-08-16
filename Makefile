NAME = push_swap
LIBRARY = push_swap.h
CFLAGS= -Wall -Wextra -Werror
CC = cc

RED     =   \033[38;5;161m
GREEN   =   \033[38;5;154m
YELLOW  =   \033[38;5;227m
BLUE	=   \033[38;5;81m
PURPLE  =   \033[38;5;93m
PINK	=	\033[38;5;219m
NC      =   \033[0m

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
	@printf "$(BLUE)====4 67 3 87 23====${RED}\n"
	@./push_swap "4 67 3 87 23"
	@printf "$(BLUE)====55 5554 89 98 003 -01====${YELLOW}\n"
	./push_swap 55 5554 89 98 003 -01
	@printf ""$(BLUE)====1 2 3 4 5====${GREEN}\n"
	./push_swap 1 2 3 4 5
	@printf "${NC}"

PRINT_N = $(shell grep "printf" $(SRC) | wc -l)
DEL_N = $(shell grep "//DELETE" $(SRC) | wc -l)
FILE_N = $(shell ls | grep a.out | wc -l)
FILE2_N = $(shell ls | grep *.txt | wc -l)

forbidden:
	@printf "$(BLUE)\n=====FINDING DELETEABLES=====\n\n"
	@printf "${YELLOW}"
	@grep "printf" $(SRC)
	@grep "//DELETE" $(SRC)
	@printf "${PINK}HAY %i PRINTF Y %i BLOQUES A BORRAR\n${NC}" $(PRINT_N) $(DEL_N)
	@printf "$(BLUE)\n=====SCANNING EXTRA FILES=====\n\n"
	@ls | grep a.out || true
	@ls | grep *.txt || true
	@printf "${PINK}HAY %i ARCHIVOS A BORRAR\n${NC}" $(shell expr $(FILE_N) + $(FILE2_N))
	@printf "$(BLUE)\n=====EXECUTING NORMINETTE=====\n\n${RED}"
	@norminette > /dev/null && printf "$(GREEN)OK\n" || norminette | grep Error
	@printf "${NC}"

.PHONY: all clean fclean re bonus
