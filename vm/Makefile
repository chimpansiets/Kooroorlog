# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/15 12:17:02 by svoort         #+#    #+#                 #
#    Updated: 2019/12/11 12:28:37 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= corewar

SRC		= vm.c error.c cw_lstadd.c cw_lstnew.c read_checks.c\
			print.c save_players.c check_files.c calc_position.c read_inits.c \
			arena_init.c print_mem.c memory_placement.c vm_init.c the_battle.c \
			player_checks.c cursor_checks.c cw_lstrem.c op_tab.c \
			cursor_operations.c operation_checks.c move_cursor.c \
			execute_operations.c operations1.c reverse_bytes.c \
			get_values.c #operations2.c operations3.c

OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

INCLUDES = ../includes/vm.h ../includes/op.h

INIB_FLAGS = -Wno-error=unused-parameter -Wno-error=unused-variable
ALL_FLAGS = #-Wall -Wextra -Werror
CFLAGS	=  $(ALL_FLAGS) -I../includes/ -I../libft/

all: $(INCLUDES) makefile libft $(NAME)

libft:
	@make -C ../libft

$(NAME): libft $(OBJ) $(INCLUDES)
	@gcc $(OBJ) -o $(NAME)  -L../libft -lft

clean:
	@make clean -C ../libft
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make fclean -C ../libft

re: fclean all

.PHONY: clean fclean re libft all