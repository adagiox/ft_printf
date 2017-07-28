FILES =	ft_printf.c \
		parse_format.c \
		print_list.c \
		parse_helpers.c \
		ft_putstr.c \
		ft_strnew.c \
		ft_bzero.c \
		ft_putchar.c \
		print_helpers.c

FLAGS = -Wall -Werror -Wextra

OBJ = $(FILES:%.c=%.o)

SRC = $(addprefix srcs/, $(FILES))


all:
	gcc $(SRC) $(FLAGS) main.c
# 	//ar crs
# 	//@gcc $(FILES) $(OBJ) $(FLAGS)

# test: clean all
# 	@gcc main.c
# 	@./a.out

# clean:
# 	-rm -f a.out
