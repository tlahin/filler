#header

NAME = tlahin.filler

SRCS_DIR = sources/

FUNCTIONS = main \

FILES = $(addprefix $(SRCS_DIR), $(patsubst %, %.c, $(FUNCTIONS)))
OBJECTS = $(addprefix $(SRCS_DIR), $(patsubst %, %.o, $(FUNCTIONS)))

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@make -C libft/
	@echo "Compiling.."
	@gcc $(FLAGS) -g -c $(FILES)
	@gcc $(FLAGS) -g $(OBJECTS) libft/libft.a -o $(NAME)
	@echo "Make complete."

clean :
	@echo "Removing object files.."
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean : clean
	@echo "Removing library.."
	@make -C libft/ fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
