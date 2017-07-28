FILES = ft_printf.c \
	ft_vprintf.c \
	ft_parseformat.c

FLAGS = -c -Wall -Werror -Wextra

OBJ = $(FILES:%.c=%.o)


all:
	ar crs
	@gcc $(FILES) $(OBJ) $(FLAGS)

test: clean all
	@gcc main.c
	@./a.out

clean:
	-rm -f a.out
