################  COLORS	######################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ CONFIG	TESTS	##################
#DIR				=			../srcs/
DIR_OUTS		=			outs
EXEC_OUTS		=			$(wildcard $(DIR_OUTS)/*)
#YOUR_FILES		=			# Add your files with the function you can test
TESTS			=			sample_test1 sample_test2 sample_test3
HEADERS_TEST 	= 			-Icriterion-2.4.2/include/criterion
UNAME_S			:=			$(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LIB_CRITERION	=		-Lcriterion-2.4.2/lib -lcriterion
	DEBUG			=		-g3
endif
ifeq ($(UNAME_S), Darwin)
	LIB_CRITERION 	=		-lcriterion
endif
################ CONFIG YOUR PROJECT #############
FLAGS 			= 			-Wall -Werror -Wextra
################ RULES		######################

all: create_outs_dir $(TESTS) $(EXEC_OUTS)

bypass: create_outs_dir $(TESTS)
	@echo
	-@for name in $(TESTS); do \
		echo "$(L_YELLOWB)$${name}: $(L_WHITE)"; \
		./$(DIR_OUTS)/$${name}; echo ; \
	done

create_outs_dir:
	@mkdir -p $(DIR_OUTS)

$(TESTS):
	@$(CC) $(FLAGS) $(HEADERS_TEST) $(LIB_CRITERION) $(DEBUG) $(addsuffix .c, $@) $(YOUR_FILES) -o $(addprefix ./$(DIR_OUTS)/, $@)

$(EXEC_OUTS):
	@echo "$(L_YELLOWB)$@: $(L_WHITE)" && ./$@;

clean:
#	@rm			-f $(SRCS:.c=.o)
#	@cd 		$(DIR) && $(MAKE) $@

fclean:			clean
	@rm 		-rf $(DIR_OUTS)
#	@cd 		$(DIR) && $(MAKE) $@

re: fclean all

.PHONY: re fclean clean all $(TESTS) $(EXEC_OUTS)