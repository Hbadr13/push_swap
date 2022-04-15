NAME = push_swap
NAME_bonus = checker
SRC = Mandatory/push_swap.c Mandatory/chick_stack.c Mandatory/instruction_1.c \
		Mandatory/instruction_2.c Mandatory/instruction_3.c \
		Mandatory/big_list.c  Mandatory/sort.c Mandatory/fonction_lst.c \
		Mandatory/big_sort.c Mandatory/chick_stack_util.c Mandatory/big_sort_util_1.c \
		Mandatory/big_sort_util_2.c Mandatory/big_list_util.c

SRC_bonus = bonus/checker.c bonus/G_N_L/get_next_line.c bonus/G_N_L/get_next_line_utils.c  bonus/chick_stack.c \
		 	bonus/instruction_2.c bonus/instruction_3.c  bonus/instruction_1.c \
		  	bonus/checker_uti_1.c bonus/checker_uti_2.c
OBJ = ${SRC:.c=.o}
OBJ_bonus = ${SRC_bonus:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERS = push_swap.h checker.h

LIBFT = libft/libft.a

GREEN  = \033[1;32m
YELLOW = \033[1;33m

all : $(NAME)

%.o:%.c  $(HEADERS)
	@$(CC) -c $< -o $@

$(NAME) : $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)---> success!"

bonus : $(OBJ_bonus)
	@$(MAKE) -C libft
	@$(CC) $(OBJ_bonus) -o $(NAME_bonus) $(LIBFT)
	@echo "$(GREEN)---> success!"

clean :
	@rm -f $(OBJ)
	@rm -f $(OBJ_bonus)
	@${MAKE} -C libft clean
	@echo "${YELLOW}---> object files deleted!"
fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_bonus)
	@${MAKE} -C libft fclean
	@echo "${YELLOW}---> all deleted!"
re : fclean all