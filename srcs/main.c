#include <stdio.h>
#include "../includes/ft_printf.h"

int main (int argc, char **argv)
{
	char *f = "%hhi\n"; 
	int i = 500;
	printf("size of long long int: %lu\n", sizeof(long long int));
	printf(f, i);
	ft_printf(f, i);
	return 1;
}
