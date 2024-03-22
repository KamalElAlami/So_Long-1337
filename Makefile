NAME = so_long
BNAME = so_long_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

FILES = ./ft_printf/ft_printf.c ./ft_printf/printtools.c ./ft_printf/printtoolss.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
CFILES = so_long.c  map_parsing.c utilities.c game_graphics.c map_checks.c move_player.c graphics_utilities.c
BFILES = ./bonus/so_long_bonus.c ./bonus/map_parsing_bonus.c ./bonus/utilities_bonus.c ./bonus/game_graphics_bonus.c ./bonus/map_checks_bonus.c ./bonus/move_player_bonus.c ./bonus/graphics_utilities_bonus.c 


INCS = ./include/ft_printf.h ./include/so_long.h ./include/get_next_line.h ./include/so_long_bonus.h

OBJ = $(FILES:.c=.o)
COBJ = $(CFILES:.c=.o)
BOBJ = $(BFILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(COBJ)
	$(CC) $(FLAGS) $^  $(MLX) -o $(NAME)

bonus : $(BNAME)

$(BNAME) : $(OBJ) $(BOBJ)
	$(CC) $(FLAGS) $^  $(MLX) -o $(BNAME)


%.o:%.c $(INCS)
	$(CC) $(FLAGS) -c  -o $< $@

clean:
	$(RM) $(OBJ) $(COBJ) $(BOBJ)

fclean: clean
	$(RM) $(OBJ) $(COBJ) $(BOBJ) $(BNAME) $(NAME)

re: fclean all
