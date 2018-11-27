NAME = menu

all: $(NAME)

$(NAME): main.c
	gcc -lncurses main.c -o $(NAME)
	
