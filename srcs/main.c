#include <stdio.h>
#include "../includes/ft_printf.h"

int main (int argc, char **argv)
{
	char *f = "% u\n"; 
	int l;
	int fl;
	unsigned int i = 4294967295;
	fl = printf(f, i);
	l = ft_printf(f, i);

	printf("Printf return: %i\nMy return:%i\n", fl, l);

	// char *str = malloc(sizeof(char) * 10);

	// printf("ACTUAL:				 -->%15p<--\n", str);
	// ft_printf("MINE:				 -->%15p<--\n", str);
	return 0;
}
