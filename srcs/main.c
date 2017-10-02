#include <stdio.h>
#include "../includes/ft_printf.h"

int main (int argc, char **argv)
{
	char *f = "%#x\n"; 
	int l;
	int fl;
	int s = 0;
	fl = printf(f, s);
	l = ft_printf(f, s);

	printf("Printf return: %i\nMy return:%i\n", fl, l);

	// char *str = malloc(sizeof(char) * 10);

	// printf("ACTUAL:				 -->%15p<--\n", str);
	// ft_printf("MINE:				 -->%15p<--\n", str);
	return 0;
}
