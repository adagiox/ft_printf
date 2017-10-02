#include <stdio.h>
#include "../includes/ft_printf.h"

int main (int argc, char **argv)
{
	char *f = "%hU\n"; 
	unsigned long i = 4294967296;
	printf(f, i);
	ft_printf(f, i);

	// char *str = malloc(sizeof(char) * 10);

	// printf("ACTUAL:				 -->%15p<--\n", str);
	// ft_printf("MINE:				 -->%15p<--\n", str);
	return 0;
}
