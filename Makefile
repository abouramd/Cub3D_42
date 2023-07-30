NAME = cub3D
DIR = ./mandatory/
SRC_PARS =
SRC_RAYC =
SRC = $(addprefix $(DIR), main.c $(addprefix pars/,$(SRC_PARS)) $(addprefix ray_casting/,$(SRC_RAYC)))
OBJ = $(SRC:.c=.o)
INC = -I libft/ -I $(DIR)include
LIB = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	INC = -I libft/ -I $(DIR)include -I ./minilibx-linux
	LIB = -L libft/ -lft -pthread -L ./minilibx-linux -lmlx_Linux -L /usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

CC:= cc
CFLAGS:= -fsanitize=address -g3
RM:= rm -rf

all:$(NAME)

$(NAME):$(OBJ)
	@make bonus -C libft
	@$(RM) $(DIR_B)main.o
	@echo "\033[1;3;34m - compile libft with the object files.\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC) $(LIB)
	@echo "\033[1;3;32m ✅ $(NAME) is done.\033[0m"

.c.o:
	@$(CC) $(CFLAGS) -c $^ -o $@ $(INC)
	@echo "\033[1;3;34m - creat $@ from $<.\033[0m"

clean:
	@make clean -C libft
	@$(RM) $(OBJ) $(OBJ_B)
	@echo "\033[1;3;31m ❎ remove the object files of $(NAME).\033[0m"

fclean:clean
	@$(RM) $(NAME) $(NAME_B)
	@rm -rf libft/libft.a
	@echo "\033[1;3;31m ❎ remove libft.a\033[0m"
	@echo "\033[1;3;31m ❎ remove $(NAME).\033[0m"

re: fclean all
