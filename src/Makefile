######################## CONFIG ##############################
NAME						=					minirt
######################## PATHS ###############################
PATH_OBJ					=					objs/
PATH_INCLUDES				=					include/
PATH_LIBFT					=					libs/libft/
VPATH						=					./srcs:linked_list			
######################## FLAGS ###############################
FLAG_W						=					-Wall -Wextra -Werror
FLAG_LIBFT					=					-L $(PATH_LIBFT) -lft
FLAG_EXTRA					=					-g3 -O3 -MMD -MP
######################## SRCS ################################
SRC							=					minirt.c draw_mini.c
SRC_LINKED_LST				=					ft_lstnew.c ft_lstsize.c ft_lstlast.c \
												ft_lstclean.c ft_lstadd_back.c 
OBJ							=					$(patsubst %.c, $(PATH_OBJ)%.o, $(SRC) $(SRC_LINKED_LST))
DEP							=					$(patsubst %.c, $(PATH_OBJ)%.d, $(SRC))
############## CONDITIONAL COMPILER FLAGS ####################
UNAME_S						:=					$(shell uname -s)
ifeq ($(UNAME_S), Linux)
	FLAG_MLX				=					-L../external_libs/mlx_linux -lmlx_Linux -lX11 -lXext
	INCLUDE_MLX				=					-I../external_libs/mlx_linux
#	FLAG_MLX				=					-lXext -lX11 -lmlx
endif
ifeq ($(UNAME_S), Darwin)
	FLAG_MLX				=					-L../external_libs/mlx_mac -lmlx -framework OpenGL -framework AppKit
	INCLUDE_MLX				=					-I../external_libs/mlx_mac
endif
######################## COLORS ##############################
RED							= \e[91m
GREEN						= \e[92m
YELLOW						= \e[93m
RC							= \e[0m

####################### RECIPES ##############################
all: $(NAME)

$(PATH_OBJ)%.o:	%.c
	@			$(CC)	$(FLAGS_W) $(FLAG_EXTRA) $(INCLUDE_MLX) -I$(PATH_INCLUDES) -c $< -o $@
	@			printf "$(GREEN).$(RC)"

$(PATH_OBJ):
	@			mkdir $@

$(NAME): $(PATH_OBJ) $(OBJ)
	@			printf "\n$(YELLOW)Creating LIBFT$(RC)\n"
	@			$(MAKE) -s -C $(PATH_LIBFT)
	@			echo $(PWD)
	@			$(CC)	$(FLAGS_W) $(FLAG_EXTRA) -I$(PATH_INCLUDES) $(OBJ) $(FLAG_MLX) $(INCLUDE_MLX) -o $(NAME)
	@			printf "$(GREEN)$(NAME) created$(RC)\n"

-include $(DEP)

clean:
	@			rm -rf $(PATH_OBJ)
	@			$(MAKE) -s -C $(PATH_LIBFT) clean
	@			@printf "$(RED)$(NAME) objects removed$(RC)\n"

fclean: clean
	@			rm -rf $(NAME)
	@			$(MAKE) -s -C $(PATH_LIBFT) fclean
	@			@printf "$(RED)$(NAME) removed$(RC)\n"

re: fclean all

.PHONY:			name all clean fclean re
