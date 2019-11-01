# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/15 12:14:49 by svoort         #+#    #+#                 #
#    Updated: 2019/08/15 12:16:21 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ./asm
	@make -C ./vm

clean:
	@make clean -C ./asm
	@make clean -C ./vm

fclean:
	@make fclean -C ./asm
	@make fclean -C ./vm

re:
	@make re -C ./asm
	@make re -C ./vm

.PHONY: all clean fclean re