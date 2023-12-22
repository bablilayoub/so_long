MANDA_SRCS =    ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
                ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
                ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
                ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
                ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
                ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
                ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
NAME = libft.a
HEADER = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
MANDA_OBJ = $(MANDA_SRCS:.c=.o)

$(NAME): $(MANDA_OBJ)
	@$(LIBC) $(NAME) $(MANDA_OBJ)

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(MANDA_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean