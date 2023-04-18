RED = \033[0;31m
NOCOLOR = \033[0m
GREEN = \033[0;32m
RED = \033[1;31m

PATH_SRC =			./srcs/
PATH_LIBFT =		./libft_printf/
PATH_OBJS =			./objs/

LIBFT = $(PATH_LIBFT)libftprintf.a
NAME = push_swap

FILES = $(PATH_SRC)push_swap.c $(PATH_SRC)misc.c $(PATH_SRC)small_stack.c $(PATH_SRC)linked_list.c $(PATH_SRC)instructions.c $(PATH_SRC)radix.c $(PATH_SRC)parsing.c
OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = -Wextra -Werror -Wall
RM = rm -rf

GUI = python3 pyviz.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`

all: logo $(NAME)

logo :
			@tput setaf 2; cat ascii/42pushswap; tput setaf default

$(NAME): $(OBJS)
	@$(MAKE) -C $(PATH_LIBFT)
	@echo "Assembling $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "${GREEN}✓${NOCOLOR}"
	@echo "$(GREEN)Compilation is done$(NOCOLOR)"

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@echo "Compiling $^: "
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}✓${NOCOLOR}"

clean:
	@echo "${RED}Cleaning objects in push_swap: ${NOCOLOR}"
	@$(RM) $(PATH_OBJS)
	@echo "${GREEN}✓${NOCOLOR}"

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@echo "${RED}Cleaning all in push_swap: ${NOCOLOR}"
	@$(RM) $(NAME)
	@echo "${GREEN}✓${NOCOLOR}"

re: fclean all

norme: 
	norminette $(PATH_SRC) $(PATH_LIBFT) ./includes

gui : all
	@$(GUI)
	@make fclean

.PHONY: re all fclean clean norme