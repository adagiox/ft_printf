#include <stdio.h>
#include "../includes/ft_printf.h"

int main (int argc, char **argv)
{
	char *f = "%-#10.4x\n"; 
	unsigned long long int i = 42;
	printf(f, i);
	//printf(f, i);
	ft_printf(f, i);
	return 0;
}
