NAME = libftprintf.a

FILES =	ft_printf.c \
		print_helpers.c \
		format_int.c \
		format_uint.c \
		format_oct.c \
		format_hex.c \
		convert.c \
		convert_wc.c \
		print_str.c \
		setup.c \
		cast_int.c \
		handle_percent.c \
		libft_print.c \
		libft_wprint.c \
		libft_digits.c \
		libft_nbrprint.c \

FLAGS = -Wall -Werror -Wextra -c

SRC = $(addprefix srcs/, $(FILES))

OBJ = ft_printf.o \
		print_helpers.o \
		format_int.o \
		format_uint.o \
		format_oct.o \
		format_hex.o \
		convert.o \
		convert_wc.o \
		print_str.o \
		setup.o \
		cast_int.o \
		handle_percent.o \
		libft_print.o \
		libft_wprint.o \
		libft_digits.o \
		libft_nbrprint.o \

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC)
	@ar rcs $(NAME) *.o
# 	//@gcc $(FILES) $(OBJ) $(FLAGS)

test:
	@gcc $(SRC) srcs/main.c
	@./a.out
	@make fclean

clean:
	@rm -rf $(OBJ)
	@rm -f a.out

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re