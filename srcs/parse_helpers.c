#include "../includes/ft_printf.h"

// Get the size of the substring in the format string to print 
//  (no arg)

int str_size(char *str)
{
	int size = 0;
	while (!(str[size] == '%' || str[size] == '\0'))
		size++;
	return size;
}