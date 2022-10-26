NAME 		=push_swap
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

bonus:
	@make bonus -C libft
	@cp libft/libft.h .
	@cp libft/libft.a .
	@gcc $(CHECK_SRC) libft.a -I ./ -o checker
	@echo "$(BLUE)checker$(WHITE) is ready to use"

clean:
	@$(RM) libft.a
	@$(RM) libft.h
	@make fclean -C libft

norm:
	@norminette *.c *.h
	@norminette libft/*.c libft/*.h
fclean: clean
	@$(RM) $(NAME)
	@$(RM) checker
	@echo "$(CYAN)$(NAME)$(WHITE) and $(BLUE)checker$(WHITE) are deleted"

re: fclean all

rebonus: fclean bonus