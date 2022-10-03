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
SRCS =	main.c

INCLS = -I./ft_printf/includes -I./includes

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@make -C ft_printf/
	@echo "Compiling.."
	@gcc -c $(FLAGS) $(INCLS) $(addprefix $(SRCS_DIR), $(SRCS))
	@gcc $(FLAGS) $(OBJS) ft_printf/libftprintf.a -o $(NAME)
	@echo "Make complete."
	@make fclean -C ft_printf/

clean :
	@echo "Removing object files.."
	@make -C ft_printf/ clean
	@rm -f $(OBJS)

fclean : clean
	@echo "Removing library.."
	@make -C ft_printf/ fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
