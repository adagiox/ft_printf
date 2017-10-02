NAME = libftprintf.a

FILES =	ft_printf.c \
		libft.c

FLAGS = -Wall -Werror -Wextra -c

SRC = $(addprefix srcs/, $(FILES))

OBJ = $(SRC:srcs/%=%.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC)
	ar rcs $(NAME) *.o
# 	//@gcc $(FILES) $(OBJ) $(FLAGS)

test:
	gcc $(SRC) srcs/main.c
	./a.out

clean:
	rm *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: clean fclean all re