# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/15 12:17:02 by svoort         #+#    #+#                 #
#    Updated: 2019/12/03 14:50:11 by avan-rei      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= corewar

SRC		= vm.c error.c lstadd_player.c lstnew_player.c read_checks.c\
			print.c save_players.c check_files.c

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