NAME = so_long
SRC =	main_bonus.c args_handler_bonus.c init_game_bonus.c parse_map_bonus.c \
		parse_utils_bonus.c utils_bonus.c render_bonus.c handle_keys_bonus.c \
		handle_keys_utils_bonus.c valid_map_bonus.c enemy_bonus.c enemy_utils_bonus.c \
		teleport_bonus.c teleport_utils_bonus.c
LIBS =	../libs/ft_printf/libftprintf.a ../libs/libft/libft.a \
		../libs/get_next_line/get_next_line.c ../libs/get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit
HEADER= so_long_bonus.h

all: comp_start $(NAME)

comp_start:
	@echo "Preparing libraries ..."
	@cd ../libs/libft && make
	@cd ../libs/ft_printf && make

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
	@./$(NAME) "../maps/map3.ber"

clean:
	@echo "- Removing object files..."
	@cd ../libs/libft && make clean
	@cd ../libs/ft_printf && make clean
	@rm -rf $(OBJ)

fclean: clean
	@echo "- Removing $(NAME)..."
	@cd ../libs/libft && make fclean
	@cd ../libs/ft_printf && make fclean
	@rm -rf $(NAME)

re: fclean all
