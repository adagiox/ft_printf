#include <stdio.h>
#include "../includes/ft_printf.h"

int main (int argc, char **argv)
{
	char *f = "%lli\n"; 
	long long int i = 4294959296;
	printf(f, i);
	//printf(f, i);
	ft_printf(f, i);
	return 0;
}
