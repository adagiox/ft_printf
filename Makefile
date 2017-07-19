all:
	@gcc ft_printf.c

test: clean all
	@./a.out

clean:
	@rm a.out
