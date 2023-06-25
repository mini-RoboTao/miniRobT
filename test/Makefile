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
# EXEC_OUTS		=			$(wildcard $(DIR_OUTS)*)
#YOUR_FILES		=			# Add your files with the function you can test
TESTS			=			sample_test1 sample_test2
HEADERS_TEST 	= 			-Icriterion-2.4.2/include/criterion
LIB_CRITERION	=			-Lcriterion-2.4.2/lib -lcriterion

PWD				=			$$PWD
################ CONFIG YOUR PROJECT #############
FLAGS 			= 			-Wall -Werror -Wextra
################ RULES		######################

all: $(TESTS)
	@echo
	-@for name in $(TESTS); do \
		echo "$(L_YELLOWB)$${name}$(L_WHITE)"; \
		./$(DIR_OUTS)/$${name}; echo ; \
	done

$(TESTS):
	@mkdir -p $(DIR_OUTS)
	@$(CC) $(FLAGS) $(HEADERS_TEST) $(LIB_CRITERION)	-g $(addsuffix .c, $@) $(YOUR_FILES) -o $(addprefix ./$(DIR_OUTS)/, $@)

clean:
#	@rm			-f $(SRCS:.c=.o)
#	@cd 		$(DIR) && $(MAKE) $@

fclean:			clean
	@rm 		-rf $(DIR_OUTS)
#	@cd 		$(DIR) && $(MAKE) $@

re: fclean all

.PHONY: re fclean clean all $(TESTS) $(EXEC_OUTS)