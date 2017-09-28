FILES =	ft_printf.c \
		libft.c

FLAGS = 

OBJ = $(FILES:%.c=%.o)

SRC = $(addprefix srcs/, $(FILES))


all:
	gcc $(SRC) $(FLAGS)
# 	//ar crs
# 	//@gcc $(FILES) $(OBJ) $(FLAGS)

# test: clean all
# 	@gcc main.c
# 	@./a.out

# clean:
# 	-rm -f a.out
