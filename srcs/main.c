#include <stdio.h>
#include "../includes/ft_printf.h"

int main (int argc, char **argv)
{
	char *f = "%0.10x\n"; 
	unsigned long long int i = 0;
	printf(f, i);
	//printf(f, i);
	ft_printf(f, i);
	return 0;
}
