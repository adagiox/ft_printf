#include "ft_printf.h"

// Parses the next argument (if any) to be printed
//  and returns a t_printf struct to be added to the t_plist
// Parsing will first read the format string to determine
//  the next argument and then call va_arg to retrieve it
// If the format string contains characters to be printed,
//  they are added (null terminated) with the s flag set 

t_printf *parse_subfmt(const char **format, va_list args)
{
	t_printf *data;
	data = (t_printf *)malloc(sizeof(t_printf));
	if (**format != '%' && **format != '\0')
	{
		char *str;
		str = (char *)malloc(sizeof(char) * str_size(*format) + 1);
		data->str = str;
		return data;
	}
}

// Parse the format string into a linked list

// pointer to the head of the list of parsed argument
//  ready to be converted

int parse_format(const char *format, va_list args)
{
	t_printf *print_list;	
	
	list = lstadd(print_list, parse_subftm(&format, list));
}
