# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 12:44:18 by tlahin            #+#    #+#              #
#    Updated: 2022/06/27 12:44:19 by tlahin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRCS_DIR = sources/
SRCS =	ft_printf.c \
	get_modifiers.c \
	utilities_data.c \
	utilities_1.c \
	printer.c \
	check.c \
	print_alternative.c \
	print_char.c \
	print_str.c \
	print_pointer.c \
	print_integer.c \
	print_octal.c \
	print_hex.c \
	print_unsigned.c \
	print_float.c \
	print_else.c \
	padding.c \
	caster.c \
	max.c \

INCLS = -I./libft -I./includes

OBJS_LIB = libft/*.o
OBJS = $(SRCS:.c=.o) $(OBJS_LIB)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@gcc -c $(FLAGS) $(INCLS) $(addprefix $(SRCS_DIR), $(SRCS))
	@ar rcs $(NAME) $(OBJS)

clean :
	@make -C ./libft/ clean
	@rm -f $(OBJS)

fclean : clean
	@make -C ./libft/ fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
