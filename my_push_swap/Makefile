NAME = push_swap
CFLAGS =  -Wall -Wextra -Werror

SRC =	main.c\
		creat_stack/check_numbers.c\
		creat_stack/creat_number.c\
		creat_stack/determinate_list.c\
		creat_stack/my_exit.c\
		creat_stack/number_add_stack.c\
		sort/ps_sort.c\
		sort/set_and_push.c\
		sort/sort_array.c\
		sort/sort_three.c\
		sort/utils_fonctions.c\
		sort/sort_low_numbers.c\
		stack_fonctions/add_pop_peek.c\
		stack_fonctions/stack_move_2.c\
		stack_fonctions/stack_move.c\
		stack_fonctions/stack_move_fonctions.c\
		ultis/my_split.c\
		ultis/my_atoi.c\
		my_printf/write_str.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)


fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re ftprintf