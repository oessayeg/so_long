NAME = so_long

BONUS_SRCS = $(addprefix srcs/, error_functions_bonus1.c error_functions_bonus2.c \
			 so_long_bonus.c move_functions_prime_bonus.c move_functions_bonus.c \
			 some_functions_bonus.c some_functions2_bonus.c)

all : $(NAME)

$(NAME) : $(BONUS_SRCS)
	@printf "\033[33;3m------------>Compiling<------------\033[0m\n"
	@make -C libft/ re
	@cc -Wall -Wextra -Werror $(BONUS_SRCS) libft/libft.a \
	-lmlx -framework OpenGl -framework Appkit -o $(NAME) 
	@printf "\033[35;5mSo_Long Bonus Compiled Succesfully !\033[0m\n"

clean :
	@make -C libft/ clean
	@printf "\033[31;6mObject Files From Libft Deleted !\033[0m\n"

fclean : clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@printf "\033[31;6mSo_Long Program Deleted !\033[0m\n"

re : fclean all
