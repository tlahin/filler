# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 17:34:26 by tlahin            #+#    #+#              #
#    Updated: 2022/05/09 16:57:00 by tlahin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_toupper.c \
	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_itoa_uintmax.c \
	ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_ftoa.c ft_intlen_max.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_ftoa_helper.c \
	ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_abs.c \
	ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
	get_next_line.c ft_sqrt.c ft_intlen.c ft_strndup.c ft_str_toupper.c \
	ft_itoa_base.c ft_number_size.c ft_number_size_base.c ft_powl.c \

PRINTF_INCS = -I. -I./ft_printf/includes
PRINTF_DIR = ft_printf/sources/

PRINTF_SRCS =	$(PRINTF_DIR)ft_printf.c \
	$(PRINTF_DIR)get_modifiers.c \
	$(PRINTF_DIR)utilities_data.c \
	$(PRINTF_DIR)utilities_1.c \
	$(PRINTF_DIR)printer.c \
	$(PRINTF_DIR)check.c \
	$(PRINTF_DIR)print_alternative.c \
	$(PRINTF_DIR)print_char.c \
	$(PRINTF_DIR)print_str.c \
	$(PRINTF_DIR)print_pointer.c \
	$(PRINTF_DIR)print_integer.c \
	$(PRINTF_DIR)print_octal.c \
	$(PRINTF_DIR)print_hex.c \
	$(PRINTF_DIR)print_unsigned.c \
	$(PRINTF_DIR)print_float.c \
	$(PRINTF_DIR)print_else.c \
	$(PRINTF_DIR)padding.c \
	$(PRINTF_DIR)caster.c \
	$(PRINTF_DIR)max.c

OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = ft_printf.o get_modifiers.o utilities_data.o utilities_1.o \
	printer.o check.o print_alternative.o print_char.o print_str.o \
	print_pointer.o print_integer.o print_octal.o print_hex.o \
	print_unsigned.o print_float.o print_else.o padding.o caster.o max.o

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@gcc -c $(FLAGS) $(PRINTF_INCS) $(SRCS) $(PRINTF_SRCS)
	@ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS)

clean :
	@rm -f $(OBJS) $(PRINTF_OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
