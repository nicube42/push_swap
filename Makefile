PATH_SRC =			./srcs/
PATH_LIBFT =		./libft_printf/
PATH_OBJS =			./objs/

LIBFT = $(PATH_LIBFT)libftprintf.a
NAME = push_swap

FILES = $(PATH_SRC)push_swap.c $(PATH_SRC)misc.c $(PATH_SRC)small_stack.c $(PATH_SRC)linked_list.c $(PATH_SRC)instructions.c $(PATH_SRC)radix.c
OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = -Wextra -Werror -Wall
RM = rm -rf

GUI = python3 pyviz.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`

all: $(NAME)

$(NAME): $(OBJS)
	@echo objects done!!
	@$(MAKE) -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo program done!

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PATH_OBJS)
	@echo obj removed!

fclean: clean
	make fclean -C $(PATH_LIBFT)
	$(RM) $(NAME)
	@echo clean everything

re: fclean all

norme: 
	norminette $(PATH_SRC) $(PATH_LIBFT) ./includes

gui : all
	@$(GUI)
	@make fclean

.PHONY: re all fclean clean norme