######################## CONFIG ##############################
NAME						=					minirt
HEADERS						=					include/minirt.h
######################## PATHS ###############################
PATH_OBJ					=					objs/
PATH_INCLUDES				=					include/
PATH_LIBFT					=					libs/libft/
######################## SRCS ################################
SRC							=					minirt.c
OBJ							=					$(SRC:%.c=%.o)
######################## FLAGS ###############################
FLAG_W						=					-Wall -Wextra -Werror
FLAG_MLX					=					-lXext -lX11 #-lmlx
FLAG_LIBFT					=					-L $(PATH_LIBFT) -lft

all: $(NAME)

$(OBJ): %.o: %.c
	@			$(CC)	 -g3 $(FLAGS_W) -c $< -o $@

$(NAME): libft $(HEADERS) $(OBJ)
	@			$(CC)	-g3 $(FLAGS_W) $(FLAG_MLX) $(OBJ) -o $(NAME)

libft:
	@			$(MAKE) -C $(PATH_LIBFT) --no-print-directory

clean:
	@			rm -rf $(OBJ)

fclean: clean
	@			rm -rf $(NAME)

re: fclean all