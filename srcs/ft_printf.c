#include "../includes/ft_printf.h"

int ft_printf(const char *format, ...)
{
	int done = 0;

	va_list args;
	va_start(args, format);
	parse_format(format, args);
	va_end(args);
	return done;
}
