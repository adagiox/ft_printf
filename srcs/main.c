#include <stdio.h>
#include "../includes/ft_printf.h"

int main (int argc, char **argv)
{
	char *f = "%5%"; 
	int l;
	int fl;
	int s = 0;
	fl = printf("%1%\n");
	l = ft_printf("%1%\n");

	printf("Printf return: %i\nMy return:%i\n", fl, l);

	// char *str = malloc(sizeof(char) * 10);

	// printf("ACTUAL:				 -->%15p<--\n", str);
	// ft_printf("MINE:				 -->%15p<--\n", str);
	return 0;
}
