# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/15 12:21:38 by svoort         #+#    #+#                 #
#    Updated: 2019/11/01 17:04:45 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= asm

SRC		=  asm.c error.c read_file.c parser.c component.c component_checks.c

OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

INCLUDES = ../includes/asm.h ../includes/op.h

ALL_FLAGS = -g -Wall -Wextra -Werror
CFLAGS	=  $(ALL_FLAGS) -I../includes/ -I../libft/

all: $(INCLUDES) libft $(NAME)

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