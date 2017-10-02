NAME = libftprintf.a

FILES =	ft_printf.c \
		libft.c

FLAGS = -Wall -Werror -Wextra -c

SRC = $(addprefix srcs/, $(FILES))

OBJ = ft_printf.o libft.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC)
	ar rcs $(NAME) *.o
# 	//@gcc $(FILES) $(OBJ) $(FLAGS)

test:
	gcc $(SRC) srcs/main.c
	./a.out

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re