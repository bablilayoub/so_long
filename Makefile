NAME = so_long
SRC = main.c args_handler.c window_sizes.c window_maker.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit
LIBS = ./libs/ft_printf/libftprintf.a ./libs/libft/libft.a
HEADER= so_long.h

all: comp_start $(NAME)

comp_start:
	@echo "Preparing libraries ..."
	@cd ./libs/libft && make
	@cd ./libs/ft_printf && make

$(NAME): comp_start $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(LINKS) $(LIBS) -o $(NAME)
	@echo "- Compiled -"
	@rm $(OBJ)
	@echo "Deleted object files"

$(OBJ): $(SRC) $(HEADER)
	@echo "- Making object files..."
	@$(CC) $(CFLAGS) -c $(SRC)

exe: all
	@echo "- Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n- Done -"

clean:
	@echo "- Removing object files..."
	@cd ./libs/libft && make clean
	@cd ./libs/ft_printf && make clean
	@rm -rf $(OBJ)

fclean: clean
	@echo "- Removing $(NAME)..."
	@cd ./libs/libft && make fclean
	@cd ./libs/ft_printf && make fclean
	@rm -rf $(NAME)

re: fclean all
