##
## EPITECH PROJECT, 2022
## makefile cat
## File description:
## Makefile
##

SRC		=	src/main.c \
			src/my_get_obj.c \
			src/my_str_to_int.c \
			src/move_plane.c \
			src/my_strlen.c \
			src/init_things.c \
			src/set_things.c \
			src/draw_things.c \
			src/add_things.c \
			src/check_collision.c \
			src/check_touch.c \
			src/my_compute_power_rec.c \
			src/my_compute_square_root.c \
			src/check_finish.c \
			src/check_script.c \
			src/put_float_to_str.c \
			src/print_timer.c

OBJ		=	$(SRC:.c=.o)

NAME 		= my_radar

CSFML =     -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

all: $(NAME)

$(NAME):
				gcc -o $(NAME) $(SRC) $(CSFML)
				make clean

clean:
				rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
