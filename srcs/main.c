#include <stdio.h>
#include "../includes/ft_printf.h"

int main (int argc, char **argv)
{
	char *f = "%hhi\n"; 
	long long int i = 4294959296;
	printf("%i\n", i);
	// printf(f, i);
	// ft_printf(f, i);
	return 1;
}
