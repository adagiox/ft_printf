#include "../includes/ft_printf.h"

int vprintf(const char *format, va_list args)
{
	while (*format)
	{
		if (*format == '%')
		{}//set_flags(&format, args);
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	return 1;
}

int ft_printf(const char *format, ...)
{
	int done;
	va_list args;

	va_start(args, format);
	done = vprintf(format, args);
	va_end(args);
	return done;
}

int main()
{
	ft_printf("Hello World!\n");
	return 1;
}