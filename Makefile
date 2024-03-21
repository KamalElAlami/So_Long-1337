NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

FILES = ./ft_printf/ft_printf.c ./ft_printf/printtools.c ./ft_printf/printtoolss.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c map_parsing.c utilities.c game_graphics.c map_checks.c move_player.c graphics_utilities.c 
CFILES = so_long.c


INCS = ./include/ft_printf.h ./include/so_long.h ./include/get_next_line.h 

OBJ = $(FILES:.c=.o)
COBJ = $(CFILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(COBJ)
	$(CC) $(FLAGS) $^  $(MLX) -o $(NAME)
%.o:%.c $(INCS)
	$(CC) $(FLAGS) -c  -o $< $@

clean:
	$(RM) $(OBJ) $(COBJ)

fclean: clean
	$(RM) $(OBJ) $(COBJ) $(NAME)

re: fclean all
