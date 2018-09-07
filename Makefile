NAMEC = checker

NAMEP = push_swap

SRCSC = srcs/checker.c \
		srcs/parsing.c \
		srcs/stack_ops.c \
		srcs/error.c \
		srcs/functionsC.c \
		srcs/issorted.c \
		srcs/Cmoves.c \
		srcs/free_list.c

SRCSP = srcs/push_swap.c \
		srcs/parsing.c \
		srcs/error.c \
		srcs/stack_ops.c \
		srcs/issorted.c \
		srcs/functionsPS.c \
		srcs/sorting.c \
		srcs/free_list.c

FLAGS = -Wall -Wextra -Werror -I./includes

OBJSC = $(SRCSC:.c=.o)

OBJSP = $(SRCSP:.c=.o)

all: makelib $(NAMEC) $(NAMEP)

makelib:
	@make -C libft

$(NAMEC): $(OBJSC)
	@gcc -o $(NAMEC) $(OBJSC) libft/libft.a
	@echo "Checker done"

$(NAMEP): $(OBJSP)
	@gcc -o $(NAMEP) $(OBJSP) libft/libft.a
	@echo "Push_swap done"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I./includes

clean:
	@make clean -C libft
	@rm -rf $(OBJSC) $(OBJSP)
	@echo "Clean done"

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf $(OBJSC)
	@/bin/rm -rf $(OBJSP)
	@/bin/rm -rf $(NAMEC)
	@/bin/rm -rf $(NAMEP)
	@echo "Fclean done"

re: fclean all
