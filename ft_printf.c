#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int done;

	va_list args;
	va_start(args, format);
	while(va_arg())
	done = ft_vprintf(format, args);
	va_end(args);
	return done;
}
