NAME = so_long

LIBNAME = so_long.a

SRCS  = $(addsuffix .o, error_functions1 error_functions2 \
		move_functions so_long move_functions_prime)

BONUS_SRCS = $(addsuffix .o, error_functions_bonus1 error_functions_bonus2 \
			 so_long_bonus move_functions_prime_bonus move_functions_bonus \
			 some_functions_bonus some_functions2_bonus)

all : $(NAME)

$(NAME) : $(SRCS)
	@printf "\033[33;3m------------>Compiling<------------\033[0m\n"
	@make -C libft/ re
	@cc -Wall -Wextra -Werror $(SRCS) libft/libft.a \
	-lmlx -framework OpenGl -framework Appkit -o $(NAME) 
	@printf "\033[35;5mSo_Long Program Compiled Succesfully !\033[0m\n"

bonus : $(LIBNAME)

$(LIBNAME) : $(BONUS_SRCS)
	@printf "\033[33;3m------------>Compiling<------------\033[0m\n"
	@make -C libft/ re
	@cc -Wall -Wextra -Werror $(BONUS_SRCS) libft/libft.a \
	-lmlx -framework OpenGl -framework Appkit -o $(NAME) 
	@ar -rc $(LIBNAME) $(BONUS_SRCS)
	@printf "\033[35;5mSo_Long Bonus Compiled Succesfully !\033[0m\n"

%.o :%.c
	@cc -Wall -Wextra -Werror -c $<

clean :
	@make -C libft/ clean
	@rm -rf $(SRCS) $(BONUS_SRCS)
	@printf "\033[31;6mSome Files Deleted !\033[0m\n"

fclean : clean
	@make -C libft/ fclean
	@rm -rf $(NAME) $(LIBNAME)
	@printf "\033[31;6mSo_Long Program Deleted !\033[0m\n"

re : fclean all
