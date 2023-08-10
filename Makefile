NAME = push_swap
LIBRARY = push_swap.h
CFLAGS= -Wall -Wextra -Werror
CC = cc

SRC = push_swap.c argv_cleaner.c utils.c sort5.c

OBJS = $(SRC:.c=.o)

LIBFTOBJS = ft_isalpha.o ft_memchr.o ft_memset.o ft_strncmp.o ft_isascii.o ft_memcmp.o\
	ft_strchr.o	ft_strrchr.o ft_bzero.o ft_isdigit.o ft_memcpy.o ft_strlcpy.o\
	ft_tolower.o ft_isalnum.o ft_isprint.o ft_memmove.o ft_strlen.o ft_toupper.o ft_strlcat.o\
	ft_atoi.o ft_strnstr.o ft_calloc.o ft_putstr_fd.o ft_strdup.o ft_striteri.o ft_strmapi.o\
	ft_putchar_fd.o ft_itoa.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_putendl_fd.o\
	ft_putnbr_fd.o ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o\
	ft_lstadd_back_bonus.o ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o

%.o: %.c $(LIBRARY) Makefile
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	ar -crs $(NAME) $(OBJS) $(LIBFTOBJS)

clean:
	rm -f $(OBJS) $(BONUSOBJS) $(LIBFTOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus