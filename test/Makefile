######################## COLORS	      ###############################
L_RED							=			\033[0;31m
L_REDB							=			\033[1;31m
L_WHITE							=			\033[0;37m
L_WHITEB						=			\033[1;37m
L_YELLOW						=			\033[0;33m
L_YELLOWB						=			\033[1;33m
L_GREEN							=			\033[0;32m
L_GREENB						=			\033[1;32m
######################## CONFIG	TESTS ###############################
HEADERS_TEST					= 			-Icriterion-2.4.2/include/criterion
FLAGS 							= 			-Wall -Werror -Wextra -g3 -O3 -MMD -MP
UNAME_S			:=			$(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LIB_CRITERION	=		-Lcriterion-2.4.2/lib -lcriterion
	DEBUG			=		-g3
	FLAG_MLX				=					-L../external_libs/mlx_linux -lmlx_Linux -lX11 -lXext
	INCLUDE_MLX				=					-I../external_libs/mlx_linux
endif
ifeq ($(UNAME_S), Darwin)
	LIB_CRITERION 	=		-lcriterion
	FLAG_MLX				=					-L../external_libs/mlx_mac -lmlx -framework OpenGL -framework AppKit
	INCLUDE_MLX				=					-I../external_libs/mlx_mac
endif
######################## PATHS 		  ###############################
PATH_OBJ						=			objs/
DIR_OUTS						=			outs/
OBJS_PROJECT					=			../src/objs/
UNIT_PATH						=			./unit_test/
VPATH							=			./unit_test/object_feature_test ./unit_test/color_feature_test
######################## PROJECT FILES ##############################
SRC_EXCLUDED					=			$(addprefix $(OBJS_PROJECT),		\
											draw_mini.o							\
											minirt.o)
SRC_PROJECT						=			$(filter-out $(SRC_EXCLUDED),		\
											$(wildcard $(OBJS_PROJECT)*.o))
######################## TEST SOURCES ###############################
SRC_OBJ_FEATURE					=			create_object_test.c object_arithmetic_test.c cap2_color_tests.c
SRC								=			$(SRC_OBJ_FEATURE)
OBJ								=			$(patsubst %.c, $(PATH_OBJ)%.o, $(SRC))
DEP								=			$(patsubst %.c, $(PATH_OBJ)%.d, $(SRC))
EXEC_OUTS						=			$(wildcard $(DIR_OUTS)*)
######################## RULES		  ###############################

all: create_outs_dir make_minirobt $(PATH_OBJ) $(OBJ) $(EXEC_OUTS)

$(PATH_OBJ)%.o:	%.c
	@			$(CC) $(FLAGS) $(INCLUDE_MLX) $(HEADERS_TEST) -I$(UNIT_PATH) -I$(UNIT_PATH) -c $< -o $@
	@			$(CC) $(FLAGS) $(FLAG_MLX) $(INCLUDE_MLX) $(HEADERS_TEST) $(LIB_CRITERION) -I$(UNIT_PATH) -g \
				$@ $(SRC_PROJECT) -o $(subst $(PATH_OBJ), $(DIR_OUTS), $(basename $@))
	@			echo "$(L_GREEN)[$(subst objs/,,$@) compiled]$(L_WHITE)"

$(PATH_OBJ):
	@			mkdir $@

-include $(DEP)

bypass: create_outs_dir $(TESTS)
	@echo
	-@for name in $(TESTS); do \
		echo "$(L_YELLOWB)$${name}: $(L_WHITE)"; \
		./$(DIR_OUTS)/$${name}; echo ; \
	done

make_minirobt:
	@			$(MAKE) -s -C ../src
	@			echo "$(L_YELLOWB)[Make MiniRobT Objects]$(L_WHITE)"

create_outs_dir:
	@			mkdir -p $(DIR_OUTS)

$(EXEC_OUTS):
	@			echo "$(L_YELLOWB)[Run Test: $(L_WHITEB)$@$(L_YELLOWB)]: $(L_WHITE)" && ./$@;

clean:
	@			$(MAKE) -s -C ../src $@
	@			rm -rf objs
	@			echo "$(L_RED)[$(L_YELLOW)Objects Removed! $(L_RED)$(OBJ)]$(L_WHITE)"

fclean: clean
	@			$(MAKE) -s -C ../src $@
	@			rm -rf outs
	@			echo "$(L_RED)[$(L_YELLOW)Removed! $(L_RED)$(EXEC_OUTS)]$(L_WHITE)"

re: fclean all

.PHONY: re fclean clean all $(TESTS) $(EXEC_OUTS)