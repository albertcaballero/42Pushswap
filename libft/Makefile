NAME = libft.a
BNAME = .bonus
LIBRARY = libft.h
CFLAGS= -Wall -Wextra -Werror -I.
CC = cc

GREEN   =   \033[1;92m
RED     =   \033[1;91m
NC      =   \033[0m
YELLOW  =   \033[1;33m

SRC = ft_isalpha.c ft_memchr.c	ft_memset.c\
	ft_strncmp.c ft_isascii.c	ft_memcmp.c\
	ft_strchr.c	ft_strrchr.c	ft_bzero.c\
	ft_isdigit.c ft_memcpy.c	ft_strlcpy.c\
	ft_tolower.c ft_isalnum.c ft_isprint.c ft_memmove.c\
	ft_toupper.c ft_strlcat.c\
	ft_atoi.c ft_strnstr.c ft_calloc.c\
	ft_strdup.c ft_striteri.c ft_strmapi.c\
	ft_itoa.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_putendl_fd.c
#ft_strlen.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c
OBJS = $(SRC:.c=.o)

BONUSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUSOBJS = $(BONUSRC:.c=.o)

%.o: %.c $(LIBRARY) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	ar -crs $(NAME) $(OBJS)
	

bonus: $(BNAME)
$(BNAME): $(BONUSOBJS) $(OBJS)
	ar -crs $(NAME) $(BONUSOBJS) $(OBJS)
	touch $@

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

forbidden:
	@printf "${RED}"
	@grep "printf" $(SRC)
	@printf "${YELLOW}There are %i printfs!! ${RED}\n" $(PRINT_N)
	@grep //DELETE $(SRC) || true
	@printf "${RED}"
	@norminette > /dev/null && printf "$(GREEN)OK\n" || norminette | grep Error
	@printf "${NC}"

.PHONY: all clean fclean re bonus
