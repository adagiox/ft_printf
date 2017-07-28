#include "../includes/ft_printf.h"

// Parses the next argument (if any) to be printed
//  and returns a t_printf struct to be added to the t_plist
// Parsing will first read the format string to determine
//  the next argument and then call va_arg to retrieve it
// If the format string contains characters to be printed,
//  they are added (null terminated) with the s flag set 

t_printf *parse_subfmt(char **format, va_list args)
{
	t_printf *data;
	va_arg(args, char *);
	data = (t_printf *)malloc(sizeof(t_printf));
	if (**format != '%' && **format != '\0')
	{
		char *str;
		str = ft_strnew(str_size(*format));
		strncpy(str, *format, str_size(*format));
		data->str = str;
		return data;
	}
	return data;
}

// Parse the format string into a linked list

int parse_format(const char *format, va_list args)
{
	t_plist *list = NULL;
	char *fmt;
	fmt = (char *)format;
	
	list = lstadd(list, parse_subfmt(&fmt, args));
	print_buffer(list);
	return 1;
}
