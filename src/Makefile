######################## CONFIG ##############################
NAME						=					miniRT
######################## PATHS ###############################
PATH_OBJ					=					objs/
PATH_INCLUDES				=					include/
PATH_LIBFT					=					libs/libft/
VPATH						=					./srcs								\
												./linked_list						\
												./object_feature					\
												./object_colors						\
												./canvas							\
												./clean_feature 					\
												./matrix_feature					\
												./ray_feature						\
												./matrix_transformations			\
												./light_and_shading					\
												./world_feature						\
												./shape_feature						\
												./reflection_and_refraction			\
												./patterns							\
												./data_validation
######################## FLAGS ###############################
FLAG_W						=					-Wall -Wextra -Werror
FLAG_LIBFT					=					-L $(PATH_LIBFT) -lft
FLAG_EXTRA					=					 -g3 -O3 -MMD -MP
######################## SRCS ################################
SRC_WORLD_FEATURE					=					handle_world.c						\
														view_transformation.c				\
														camera.c
SRC_LIGHT_AND_SHADING				=					normal_at.c							\
														reflect.c							\
														the_phong_reflection.c				\
														shadows.c
SRC_RAY_FEATURE						=					handle_ray.c						\
														intersections.c						\
														transforming_rays.c
SRC_MATRIX_TRANSFORMATION			=					translate_matrix.c					\
														scaling_matrix.c					\
														rotation_matrix.c					\
														shearing_matrix.c
SRC_MATRIX_FEATURE					=					handle_matrix.c						\
														matrix_operations.c					\
														inverting_matrix.c					\
														matrix_utils.c
SRC_CLEAN_FEATURE					=					free_feature.c
SRC_OBJECT_FEATURE					=					create_object.c						\
														object_arithmetic.c					\
														handle_object.c
SRC_COLORS_FEATURE					=					object_colors.c
SRC_CANVAS_FEATURE					=					canvas.c
SRC_SHAPES_FEATURE					=					shapes.c							\
														sphere.c							\
														plane.c								\
														cube.c								\
														cylinder.c							\
														cylinder_cap.c						\
														cone.c								\
														cone_cap.c							\
														light.c
SRC_REFLECTION_AND_REFRACTION		=					reflection.c						\
														transparency_and_refraction.c
SRC_LINKED_LST						=					ft_lstnew.c							\
														ft_lstsize.c						\
														ft_lstlast.c						\
														ft_lstclean.c						\
														ft_lstadd_back.c					\
														ft_lstremove.c
SRC_PATTERNS_FEATURE				=					striped_pattern.c					\
														transforming_patterns.c				\
														generalizing_patterns.c				\
														gradient_pattern.c					\
														ring_pattern.c						\
														checkers_pattern.c
SRC_DATA_VALIDATION					=					parser.c							\
														axis_and_float_utils.c				\
														rgb_utils.c							\
														shape_define.c						\
														define_light_and_cam.c				\
														data_validation.c					\
														input_validation.c					\
														arctan.c
SRC									=					minirt.c											\
														utils.c												\
														objs.c												\
														aux_math.c											\
														errors.c											\
														$(SRC_LINKED_LST) 									\
														$(SRC_OBJECT_FEATURE) 								\
														$(SRC_COLORS_FEATURE) 								\
														$(SRC_CANVAS_FEATURE)								\
														$(SRC_CLEAN_FEATURE)								\
														$(SRC_MATRIX_FEATURE)								\
														$(SRC_RAY_FEATURE)									\
														$(SRC_LIGHT_AND_SHADING)							\
														$(SRC_MATRIX_TRANSFORMATION)						\
														$(SRC_WORLD_FEATURE)								\
														$(SRC_SHAPES_FEATURE)								\
														$(SRC_REFLECTION_AND_REFRACTION)					\
														$(SRC_PATTERNS_FEATURE)								\
														$(SRC_DATA_VALIDATION)
OBJ									=					$(patsubst %.c, $(PATH_OBJ)%.o, $(SRC))
DEP									=					$(patsubst %.c, $(PATH_OBJ)%.d, $(SRC))
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
	@			$(CC)	$(FLAGS_W) $(FLAG_EXTRA) $(INCLUDE_MLX) -I$(PATH_INCLUDES) -I$(PATH_LIBFT) -c $< -o $@
	@			printf "$(GREEN).$(RC)"

$(PATH_OBJ):
	@			mkdir $@

$(NAME): $(PATH_OBJ) $(OBJ)
	@			printf "\n$(YELLOW)Creating LIBFT$(RC)\n"
	@			$(MAKE) -s -C $(PATH_LIBFT)
	@			echo $(PWD)
	@			$(CC)	$(FLAGS_W) $(FLAG_EXTRA)  -I$(PATH_INCLUDES) $(OBJ) $(FLAG_MLX) $(INCLUDE_MLX) -o $(NAME) -lm $(FLAG_LIBFT)
	@			printf "$(GREEN)$(NAME) created$(RC)\n"

-include $(DEP)

v: all
	valgrind --leak-check=full --show-leak-kinds=all ./miniRT $(VAR)

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
