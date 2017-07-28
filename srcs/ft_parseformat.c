#include "ft_printf.h"

int parse_format(const char *format, va_list args)
{
	t_printf *print_list;	// pointer to the head of the list of parsed argument
							// ready to be converted
	
	list = parse_subftm(format, list);
}
