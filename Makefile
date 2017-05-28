all:
	@gcc ft_printf.c

test: all
	@./a.out
