#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int done;

	va_list args;
	va_start(args);
	done = ft_vprintf(format, args);
	va_end(args);
}
