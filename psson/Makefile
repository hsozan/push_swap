NAME 		=pushswap
CC	 		=gcc -Wall -Werror -Wextra
RM			=rm -rf
SRC			=$(shell find . ! -name "ps_checker.c" -name "*.c")
CHECK_SRC	=$(shell find . ! -name "pushswap.c" -name "*.c")
CYAN		= \033[0;96m
BLUE		= \033[0;94m
WHITE		= \033[0;97m

all: $(NAME)

$(NAME):
	@make bonus -C libft
	@cp libft/libft.h .
	@cp libft/libft.a .
	@gcc $(SRC) libft.a -I ./ -o $(NAME)
	@echo "$(CYAN)$(NAME)$(WHITE) is ready to use"

check:
	@make bonus -C libft
	@cp libft/libft.h .
	@cp libft/libft.a .
	@gcc $(CHECK_SRC) libft.a -I ./ -o check
	@echo "$(BLUE)checker$(WHITE) is ready to use"

clean:
	@$(RM) libft.a
	@$(RM) libft.h
	@make fclean -C libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) check
	@echo "$(CYAN)$(NAME)$(WHITE) and $(BLUE)checker$(WHITE) are deleted"

re: fclean all

rec: fclean check