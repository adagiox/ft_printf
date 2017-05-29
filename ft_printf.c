#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	char *str = "Test string.";
	int i = -10;
	int j = 10;

	printf("%s\n", str);
	printf("%+i\n",i);
	printf("% i\n",j);
	return 0;
}
