# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/24 16:34:33 by svoort         #+#    #+#                 #
#    Updated: 2019/11/02 15:34:36 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -c
SRCS =	ft_atoi.c ft_bzero.c ft_countwords.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c \
		ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_memalloc_2d.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		ft_memset.c ft_pow.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
		ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
		ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c \
		ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strndup.c \
		ft_joinfree.c ft_dblhex.c ft_itoabase.c ft_nbrlen.c ft_prfdbl.c \
		ft_prfnbr.c ft_prfoper.c ft_printf.c ft_qstr.c ft_unicode.c \
		helper1.c helper2.c helper3.c helper4.c helper5.c helper6.c \
		helper7.c ft_is_int.c ft_isspace.c get_next_line.c \
		ft_strcdup.c ft_strnchr.c ft_strsplit_free.c ft_strsplit_len.c \
		ft_isint.c ft_strccpy.c
INCLUDES = -I .
NAME = libft.a
OBJ = $(SRCS:.c=.o)

# Colors
RED				= \033[31;1m
GREEN		    = \033[32;1m
YELLOW			= \033[33;1m
BLUE			= \033[34;1m
PURPLE			= \033[35;1m
CYAN			= \033[36;1m
LGREY			= \033[37;1m
END_C			= \033[m
CLEAR			= "\033[K"

all: $(NAME)

$(NAME):
	@printf "\r" && printf $(CLEAR) && printf "$(RED)Libft building...$(END_C)"
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDES)
	@ar rc $(NAME) $(OBJ)
	@printf "\r" && printf $(CLEAR) && printf "$(GREEN)Libft built!\r$(END_C)"
	@sleep 1
	
clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
.SILENT:
