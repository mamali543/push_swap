
MakeDir = make
compile = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAMEB = checker

SRC = push_swap.c\
	  push.c\
	  rotate.c\
	  help_functions.c\
	  help_functions2.c\
	  help_functions3.c\
	  swap.c\
	  get_next_line.c\
	  libft_tools.c\
	  fill_stack.c\
	  libft_tools2.c\
	  sort.c\
	  sort2.c\
	  sort3.c\
	  tools.c

SRCB = 	push.c\
		rotate.c\
		swap.c\
		help_functions.c\
		help_functions2.c\
		help_functions3.c\
		get_next_line.c\
		libft_tools2.c\
		libft_tools.c\
		ft_split.c\
		fill_stack.c\
		checker.c\
		tools.c

all: $(NAME)

$(NAME): $(SRC)
	@$(compile) $(SRC) $(FLAGS) -o $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(SRCB)
	@$(compile) $(SRCB) $(FLAGS) -o $(NAMEB)

fclean:
	@rm -rf $(NAME) $(NAMEB)

re: fclean all