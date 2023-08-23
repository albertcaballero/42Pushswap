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

SRC = push_swap.c argv_cleaner.c utils.c sort5.c algorithm.c\
	m_push.c m_revrotate.c m_rotate.c m_swap.c

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
	@grep "printf" $(SRC) || true
	@grep "//DELETE" $(SRC) || true
	@printf "${PINK}HAY %i PRINTF Y %i BLOQUES A BORRAR\n${NC}" $(PRINT_N) $(DEL_N)
	@printf "$(BLUE)\n=====SCANNING EXTRA FILES=====\n\n"
	@ls | grep a.out || true
	@ls | grep *.txt || true
	@printf "${PINK}HAY %i ARCHIVOS A BORRAR\n${NC}" $(shell expr $(FILE_N) + $(FILE2_N))
	@printf "$(BLUE)\n=====EXECUTING NORMINETTE=====\n\n${RED}"
	@norminette > /dev/null && printf "$(GREEN)	---OK---\n\n" || norminette | grep Error
	@printf "${NC}"

ARG1="94 52 54 95 53 62 90 19 12 87 22 78 49 81 73 33 69 93 32 83 47 1 11 23 50 65 51 20 16 58 56 46 44 30 27 3 25 89 9 13 99 39 6 45 0 60 18 75 31 71 59 61 10 8 96 66 41 36 76 43 86 55 48 98 63 7 42 70 74 40 68 34 57 5 79 84 21 38 88 29 64 72 80 97 92 37 35 4 14 85 67 24 91 28 17 15 2 82 77 26"
ARG2="0"
ARG3="0"
ARG4="0"
ARG5="0"

check:
#	@./push_swap $(ARG1)
	@./push_swap $(ARG1) | ./checker_Mac $(ARG1)
# ./push_swap $(ARG3) | ./checker_Mac $(ARG3)
# ./push_swap $(ARG4) | ./checker_Mac $(ARG4)
# ./push_swap $(ARG5) | ./checker_Mac $(ARG5)

.PHONY: all clean fclean re bonus
