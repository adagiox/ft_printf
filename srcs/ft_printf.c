#include "../includes/ft_printf.h"

int set_flags(const char *format, va_list args)
{
	if (*format == 'c')
	{
		char c;
		c = va_arg(args, int);
		write(1, &c, 1);
	}
	return 1;
}

int vprintf(const char *format, va_list args)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			set_flags(format, args);
			format++;
		}
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
	char c = '$';
	//printf("The best programming language is... %c\n", c);
	ft_printf("The best programming language is... %c\n", c);
	return 1;
}