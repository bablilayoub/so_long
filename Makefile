NAME=so_long

$(NAME):
	cd src && make all

all: $(NAME)

bonus: 
	cd src_bonus && make all

exe:
	cd src && make exe

exe_bonus:
	cd src_bonus && make exe

clean: 
	cd src && make clean
	cd src_bonus && make clean
	
fclean: 
	cd src && make fclean
	cd src_bonus && make fclean