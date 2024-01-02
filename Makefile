NAME			=	so_long
NAME_BONUS		=	so_long_bonus

SRC				=	main.c args_handler.c init_game.c parse_map.c \
					parse_utils.c utils.c render.c handle_keys.c valid_map.c
SRC_BONUS		=	./bonus/main_bonus.c ./bonus/args_handler_bonus.c ./bonus/init_game_bonus.c \
					./bonus/parse_map_bonus.c ./bonus/parse_utils_bonus.c ./bonus/utils_bonus.c \
					./bonus/render_bonus.c ./bonus/handle_keys_bonus.c ./bonus/handle_keys_utils_bonus.c \
					./bonus/valid_map_bonus.c ./bonus/enemy_bonus.c ./bonus/enemy_utils_bonus.c \
					./bonus/teleport_bonus.c ./bonus/teleport_utils_bonus.c ./bonus/render_string_bonus.c
			
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LINKS			=	-lmlx -framework OpenGL -framework AppKit
LIBS			=	./libs/ft_printf/libftprintf.a ./libs/libft/libft.a \
					./libs/get_next_line/get_next_line.c ./libs/get_next_line/get_next_line_utils.c

HEADER			=	so_long.h
HEADER_BONUS	=	./bonus/so_long_bonus.h

OBJ				=	$(SRC:.c=.o)
OBJ_BONUS		=	$(SRC_BONUS:.c=.o)

all: comp_start $(NAME)

comp_start:
	@echo "Preparing libraries ..."
	@make -C ./libs/libft
	@make -C ./libs/ft_printf

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(LINKS) $(LIBS) -o $(NAME)
	@echo "- Compiled -"

bonus: comp_start $(OBJ_BONUS)
	@echo "Compiling $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LINKS) $(LIBS) -o $(NAME_BONUS)
	@echo "- Compiled -"

%_bonus.o: %_bonus.c $(HEADER_BONUS)
	@echo "- Making bonus object file..."
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

%.o: %.c $(HEADER)
	@echo "- Making object file..."
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@echo "- Removing object files..."
	@cd ./libs/libft && make clean
	@cd ./libs/ft_printf && make clean
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@echo "- Removing $(NAME) & $(NAME_BONUS)..."
	@cd ./libs/libft && make fclean
	@cd ./libs/ft_printf && make fclean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: comp_start clean