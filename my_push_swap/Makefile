NAME = phlio
FLAG = cc -Wall -Wextra -Werror -pthread
RM = rm -rf
SRC = 	src/main.c \
		src/argv_check/argv_correct.c \
		src/argv_check/print_argv_error.c \
		src/cycle/life.c\
		src/cycle/check.c\
		src/cycle/print_status.c\
		src/cycle/take_fork.c\
		src/cycle/wait_thread.c\
		src/define_argv/create_all.c\
		src/define_argv/create_pthread.c\
		src/define_argv/define_argv.c \
		src/define_argv/mutex.c\
		src/ultis/time.c\
		src/ultis/free_all.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(FLAG) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re