NAME 		=pushswap
CC	 		=gcc -Wall -Werror -Wextra
RM			=rm -rf
SRC			=$(shell find . ! -name "ps_checker.c" -name "*.c")
CHECK_SRC	=$(shell find . ! -name "pushswap.c" -name "*.c")
CYAN		= \033[0;96m
BLUE		= \033[0;94m

all: $(NAME)

$(NAME):
	@make bonus -C libft
	@cp libft/libft.h .
	@cp libft/libft.a .
	@gcc $(SRC) libft.a -I ./ -o $(NAME)

check:
	@make bonus -C libft
	@cp libft/libft.h .
	@cp libft/libft.a .
	@gcc $(CHECK_SRC) libft.a -I ./ -o check

clean:
	@$(RM) libft.a
	@$(RM) libft.h
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) check

re: fclean all

recheck: fclean check
