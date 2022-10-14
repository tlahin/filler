# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:21:47 by tlahin            #+#    #+#              #
#    Updated: 2022/10/03 13:21:49 by tlahin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tlahin.filler

SRCS_DIR = sources/
SRCS =	main.c \
		parser.c \
		arr.c \
		utilities.c \
		heatmap.c \
		middle.c \
		solver.c \
		printer.c

INCLS = -I./ft_printf/includes -I./includes

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@make -C ft_printf/
	@echo "Compiling.."
	@gcc $(FLAGS) $(INCLS) -g -c $(addprefix $(SRCS_DIR), $(SRCS))
	@gcc $(FLAGS) -g $(OBJS) ft_printf/libftprintf.a -o $(NAME)
	@echo "Make complete."

clean :
	@echo "Removing object files.."
	@make -C ft_printf/ clean
	@rm -f $(OBJS)

fclean : clean
	@echo "Removing executabble.."
	@make -C ft_printf/ fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
