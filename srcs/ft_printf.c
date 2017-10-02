#include "../includes/ft_printf.h"
#include <locale.h>

const t_type g_dispatch_table[] = {
	{'s', convert_s},
	{'S', convert_ws},
	{'p', convert_u},
	{'d', convert_i},
	{'D', convert_i},
	{'i', convert_i},
	{'o', convert_u},
	{'O', convert_u},
	{'u', convert_u},
	{'U', convert_u},
	{'x', convert_u},
	{'X', convert_u},
	{'c', convert_c},
	{'C', convert_c},
};

int print_info(t_printf *flags)
{
	printf("\nPRINT_INFO:\nprec: %i\nprec_set: %i\nwidth: %i\nspec: %c\n\nis_short: \
		%i\nis_char: %i\nis_long: %i\nis_longlong: %i\nis_sizet: %i\nintmax: %i\nalt: \
		%i\nspace: %i\nleft: %i\nshowsign: %i\nwide: %i\npad: %i\nis_int: %i\n", 
		flags->prec, flags->prec_set, flags->width, flags->spec, flags->is_short,
		flags->is_char, flags->is_long, flags->is_longlong, flags->is_sizet, flags->intmax,
		flags->alt, flags->space, flags->left, flags->showsign, flags->wide,
		flags->pad, flags->is_int);
	return (1);
}

void pad_n(t_printf *flags, int n)
{
	while (n)
	{
		ft_putchar(flags, flags->pad_char);
		n--;
	}
}

int print_space(t_printf *flags, int n)
{
	while (n)
	{
		ft_putchar(flags, ' ');
		n--;
	}
	return (1);
}

int print_zero(t_printf *flags, int n)
{
	while (n)
	{
		ft_putchar(flags, '0');
		n--;
	}
	return (1); 
}

int print_prefix(t_printf *flags, char c)
{
	if (c == '+' || c == ' ' || c == 'x' || c == 'X')
		ft_putchar(flags, c);
	return (1);
}

char set_prefix(t_printf *flags, long long int i)
{
	char prefix;

	prefix = '*';
	if (i < 0)
		prefix = '-';
	else if (i >= 0 && flags->showsign)
		prefix = '+';
	else if (flags->space)
		prefix = ' ';
	return (prefix);
}

int format_i(t_printf *flags, long long int i)
{
	int num_space;
	char prefix;
	int num_pad;
	int num_digits;
	int num_zero;

	num_space = 0;
	num_pad = 0;
	num_zero = 0;
	prefix = set_prefix(flags, i);
	num_digits = ft_countdigits(i);
	if (num_digits < flags->prec)
	{
		num_zero = flags->prec - num_digits;
		num_digits = flags->prec;
	}
	if (prefix == '-' || prefix == '+' || prefix == ' ')
		num_digits++;
	if (num_digits < flags->width)
		num_space = flags->width - num_digits;
	if (flags->left)
	{
		print_prefix(flags, prefix);
		print_zero(flags, num_zero);
		ft_putnbr(flags, i);
		print_space(flags, num_space);
	}
	else 
	{
		if (flags->pad)
		{
			if (i < 0)
			{
				ft_putchar(flags, '-');
				i = -i;
			}
			print_prefix(flags, prefix);
			print_zero(flags, num_space);
		}
		else
		{
			print_space(flags, num_space);
			if (i < 0)
			{
				ft_putchar(flags, '-');
				i = -i;
			}
			print_prefix(flags, prefix);
		}
		print_zero(flags, num_zero);
		ft_putnbr(flags, i);
	}
	return (1);
}

char set_uprefix(t_printf *flags)
{
	char prefix;

	prefix = '*';
	if (flags->spec == 'O' || flags->spec == 'o')
		prefix = '0';
	else if (flags->spec == 'x' || flags->spec == 'p')
		prefix = 'x';
	else if (flags->spec == 'X')
		prefix = 'X';
	else if (flags->showsign)
		prefix = '+';
	else if (flags->space)
		prefix = ' ';
	return (prefix);
}

int format_u(t_printf *flags, unsigned long long int i)
{
	int num_space;
	char prefix;
	int num_pad;
	int num_digits;
	int num_zero;

	num_space = 0;
	num_pad = 0;
	num_zero = 0;
	prefix = set_uprefix(flags);
	num_digits = ft_ucountdigits(i);
	if (num_digits < flags->prec)
	{
		num_zero = flags->prec - num_digits;
		num_digits = flags->prec;
	}
	if (prefix == '+' || prefix == ' ')
		num_digits++;
	if (num_digits < flags->width)
		num_space = flags->width - num_digits;
	if (flags->left)
	{
		print_prefix(flags, prefix);
		print_zero(flags, num_zero);
		ft_uputnbr(flags, i);
		print_space(flags, num_space);
	}
	else 
	{
		if (flags->pad)
		{
			print_prefix(flags, prefix);
			print_zero(flags, num_space);
		}
		else
		{
			print_space(flags, num_space);
			print_prefix(flags, prefix);
		}
		print_zero(flags, num_zero);
		ft_uputnbr(flags, i);
	}
	return (1);
}

int format_o(t_printf *flags, unsigned long long int i)
{
	int num_space;
	int num_pad;
	int num_digits;
	int num_zero;

	num_space = 0;
	num_pad = 0;
	num_zero = 0;
	if (i == 0)
	{
		ft_putchar(flags, '0');
		return (1);
	}
	num_digits = ft_getdigits(i, 8);
	if (num_digits < flags->prec)
	{
		num_zero = flags->prec - num_digits;
		num_digits = flags->prec;
	}
	if (flags->alt)
		num_digits++;
	if (num_digits < flags->width)
		num_space = flags->width - num_digits;
	if (flags->left)
	{
		if (flags->alt && i != 0)
			ft_putchar(flags, '0');
		print_zero(flags, num_zero);
		ft_itoa_base(flags, i, 8, 0);
		print_space(flags, num_space);
	}
	else 
	{
		if (flags->pad)
		{
			if (flags->alt && i != 0)
				ft_putchar(flags, '0');
			print_zero(flags, num_space);
		}
		else
		{
			print_space(flags, num_space);
			if (flags->alt && i != 0)
				ft_putchar(flags, '0');
		}
		print_zero(flags, num_zero);
		ft_itoa_base(flags, i, 8, 0);
	}
	return (1);	
}

int format_x(t_printf *flags, unsigned long long int i)
{
	int offset;
	int num_space;
	int num_pad;
	int num_digits;
	int num_zero;
	char prefix;

	num_space = 0;
	num_pad = 0;
	num_zero = 0;
	if (i == 0)
	{
		if (flags->spec == 'p')
			ft_putstr(flags, "0x");
		ft_putchar(flags, '0');
		return (1);
	}
	prefix = set_uprefix(flags);
	num_digits = ft_getdigits(i, 16);
	if (flags->spec == 'X')
		offset = 6;
	else 
		offset = 0;
	if (num_digits < flags->prec)
	{
		num_zero = flags->prec - num_digits;
		num_digits = flags->prec;
	}
	if (flags->alt)
		num_digits += 2;
	if (num_digits < flags->width)
		num_space = flags->width - num_digits;
	if (flags->left)
	{
		if (flags->alt)
		{
			ft_putchar(flags, '0');
			print_prefix(flags, prefix);
		}
		print_zero(flags, num_zero);
		ft_itoa_base(flags, i, 16, offset);
		print_space(flags, num_space);
	}
	else 
	{
		if (flags->pad)
		{
			if (flags->alt)
			{
				ft_putchar(flags, '0');
				print_prefix(flags, prefix);
			}
			print_zero(flags, num_space);
		}
		else
		{
			print_space(flags, num_space);
			if (flags->alt)
			{
				ft_putchar(flags, '0');
				print_prefix(flags, prefix);
			}
		}
		print_zero(flags, num_zero);
		ft_itoa_base(flags, i, 16, offset);
	}
	return (1);	
}

int print_i(t_printf *flags, long long int i)
{
	if (flags->is_int)
		i = (int)i;
	else if (flags->is_short)
		i = (short)i;
	else if (flags->is_char)
		i = (char)i;
	if (flags->prec_set || flags->showsign || flags->left || flags->space || 
		flags->width > 0)
		format_i(flags, i);
	else
		ft_putnbr(flags, i);
	return (1);
}

int print_u(t_printf *flags, unsigned long long i)
{
	if (flags->is_int)
		i = (unsigned int)i;
	else if (flags->is_short)
		i = (unsigned short)i;
	else if (flags->is_char)
		i = (unsigned char)i;
	if (flags->spec == 'o' || flags->spec == 'O')
		format_o(flags, i);
	else if (flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'p')
		format_x(flags, i);
	else if (flags->prec_set || flags->showsign || flags->left || flags->space 
		|| flags->width > 0)
		format_u(flags, i);
	else
		ft_uputnbr(flags, i);
	return (1);
}

int print_s(t_printf *flags, char *s)
{
	int num_char;

	num_char = ft_strlen(s);
	if (flags->prec < num_char && flags->prec_set == 1)
		num_char = flags->prec;
	else if (flags->prec > num_char && flags->prec_set == 1)
		flags->prec = num_char;
	if (num_char < flags->width)
		flags->width = flags->width - num_char;
	if (flags->left == 1)
	{
		ft_putnstr(flags, s, num_char);
		pad_n(flags, flags->width);
	}
	else 
	{
		pad_n(flags, flags->width);
		ft_putnstr(flags, s, num_char);
	}
	return (1);
}

int print_ws(t_printf *flags, wchar_t *ws)
{
	int num_char;

	num_char = ft_wstrlen(ws);
	if (flags->prec < num_char && flags->prec_set == 1)
		num_char = flags->prec;
	else if (flags->prec > num_char && flags->prec_set == 1)
		flags->prec = num_char;
	if (num_char < flags->width)
		flags->width = flags->width - num_char;
	if (flags->left == 1)
	{
		ft_wputnstr(flags, ws, num_char);
		pad_n(flags, flags->width);
	}
	else 
	{
		pad_n(flags, flags->width);
		ft_wputnstr(flags, ws, num_char);
	}
	return (1);
}

int print_c(t_printf *flags, int c)
{
	if (flags->width > 1)
	{
		flags->width = flags->width - 1;
		if (flags->left == 1)
		{
			ft_putchar(flags, c);
			pad_n(flags, flags->width);
		}
		else
		{
			pad_n(flags, flags->width);
			ft_putchar(flags, c);
		}
	}
	else
		ft_putchar(flags, c);
	return (1);
}

int print_wc(t_printf *flags, wchar_t wc)
{
	if (flags->width > 1)
	{
		flags->width = flags->width - 1;
		if (flags->left == 1)
		{
			ft_wputchar(flags, wc);
			pad_n(flags, flags->width);
		}
		else
		{
			pad_n(flags, flags->width);
			ft_wputchar(flags, wc);
		}
	}
	else
		ft_wputchar(flags, wc);
	return (1);
}

int convert_u(t_printf *flags, va_list args)
{
	unsigned long long int u;

	if (flags->spec == 'p')
		flags->alt = 1;
	if (flags->prec_set)
		flags->pad = 0;
	if (flags->showsign)
		flags->showsign = 0;
	if (flags->space == 1)
		flags->space = 0;
	u = va_arg(args, unsigned long long int);
	print_u(flags, u);
	return (1);
}

int convert_i(t_printf *flags, va_list args)
{
	long long int i;

	if (flags->prec_set)
		flags->pad = 0;
	i = va_arg(args, long long int);
	print_i(flags, i);
	return (1);
}

int convert_s(t_printf *flags, va_list args)
{
	char *s;

	if (flags->is_long == 1)
		convert_ws(flags, args);	
	else 
	{
		if ((s = va_arg(args, char *)) == NULL)
		{
			ft_putstr(flags, "(null)");
			return 1;
		}
		print_s(flags, s);
	}
	return (1);
}

int convert_ws(t_printf *flags, va_list args)
{
	wchar_t *ws;

	if ((ws = va_arg(args, wchar_t *)) == NULL)
	{
		ft_putstr(flags, "(null)");
		return 1;
	}
	print_ws(flags, ws);
	return 1;
}

int convert_wc(t_printf *flags, va_list args)
{
	wchar_t wc;

	wc = va_arg(args, wchar_t);
	return (print_wc(flags, wc));
}

int convert_c(t_printf *flags, va_list args)
{
	int c;

	if (flags->is_long == 1)
		convert_wc(flags, args);
	else
	{
		c = va_arg(args, int);
		print_c(flags, c);
	}
	return (1);
}

t_printf *init_flags()
{
	t_printf *flags;

	flags = (t_printf *)malloc(sizeof(t_printf));
	flags->length = 0;
	flags->prec = 1;
	flags->prec_set = 0;
	flags->width = 0;
	flags->spec = '0';
	flags->pad_char = ' ';
	flags->is_short = 0;
	flags->is_char = 0;
	flags->is_long = 0;
	flags->is_longlong = 0;
	flags->is_sizet = 0;
	flags->intmax = 0;
	flags->alt = 0;
	flags->space = 0;
	flags->left = 0;
	flags->showsign = 0;
	flags->wide = 0;
	flags->pad = 0;
	flags->is_int = 1;
	return (flags);
}

int do_conversion(t_printf *flags, va_list args)
{
	int i;

	i = 0;
	while (1)
	{
		if (flags->spec == g_dispatch_table[i].spec)
		{
			g_dispatch_table[i].func(flags, args);
			break ;
		}
		i++;
	}
	return (1);
}

int set_spec(const char **f, t_printf *flags, va_list args)
{
	if (**f == 's' || **f == 'S' || **f == 'p' || **f == 'd' || **f == 'D' || 
		**f == 'i' || **f == 'o' || **f == 'O' || **f == 'u' || **f == 'U' || 
		**f == 'x' || **f == 'X' || **f == 'c' || **f == 'C')
		flags->spec = **f;
	else
		return (-1);
	(*f)++;
	if (flags->spec == 'D')
	{
		flags->is_long = 1;
		flags->is_int = 0;
	}
	if (flags->spec == 'U')
	{
		flags->is_long = 1;
		flags->is_short = 0;
		flags->is_int = 0;
	}
	if (flags->spec == 'p')
	{
		flags->is_long = 1;
		flags->is_int = 0;
	}
	return (do_conversion(flags, args));
}

int set_length(const char **f, t_printf *flags, va_list args)
{
	if (**f == 'h' && *(*f + 1) == 'h')
		flags->is_char = 1;
	else if (**f == 'l' && *(*f + 1) == 'l')
		flags->is_longlong = 1;
	else if (**f == 'j')
		flags->intmax = 1;
	else if (**f == 'z')
		flags->is_sizet = 1;
	else if (**f == 'h')
		flags->is_short = 1;
	else if (**f == 'l')
		flags->is_long = 1;
	if (flags->is_short == 1 || flags->is_long == 1 || flags->intmax == 1 ||
		flags->is_sizet == 1)
	{
		flags->is_int = 0;
		(*f)++;
	}
	else if (flags->is_char == 1 || flags->is_longlong == 1)
	{
		flags->is_int = 0;
		(*f) += 2;
	}
	if (flags->is_long == 1 || flags->is_longlong == 1 || flags->is_sizet == 1)
		flags->intmax = 1;
	return (set_spec(f, flags, args));
}

int set_prec(const char **f, t_printf *flags, va_list args)
{
	if (**f == '.')
	{
		(*f)++;
		if (ft_isdigit(**f))
		{
			flags->prec = ft_atoi(*f);
			while (ft_isdigit(**f))
				(*f)++;
		}
		else
			flags->prec = 0;
		flags->prec_set = 1;
	}
	return (set_length(f, flags, args));
}

int set_width(const char **f, t_printf *flags, va_list args)
{
	if (flags->space && flags->pad)
		flags->pad = 0;
	if (flags->showsign && flags->space)
		flags->space = 0;
	if (ft_isdigit(**f))
	{
		flags->width = ft_atoi(*f);
		while (ft_isdigit(**f))
			(*f)++;
	}
	return (set_prec(f, flags, args));
}

int set_flags(const char **f, va_list args)
{
	t_printf *flags;
	int length;
	
	if (**f == '%')
	{
		write(1, (*f)++, 1);
		return (1);
	}
	flags = init_flags();
	while (**f == '#' || **f == '-' || **f == '+' || **f == ' ' || **f == '0')
	{
		if (**f == '#')
			flags->alt = 1;
		else if (**f == '-')
			flags->left = 1;
		else if (**f == ' ')
			flags->space = 1;
		else if (**f == '+')
			flags->showsign = 1;
		else if (**f == '0')
			flags->pad = 1;
		(*f)++;
	}
	if (set_width(f, flags, args) == -1)
	{
		free(flags);
		return (-1);
	}
	length = flags->length;
	free(flags);
	return (length);
}

int vprintf(const char *f, va_list args)
{
	int length;

	length = 0;
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			if ((length += set_flags(&f, args)) == -1)
				return -1;
		}
		else
		{
			ft_nputchar(*f);
			length++;
			f++;
		}
	}
	return (length);
}

int ft_printf(const char *f, ...)
{
	int done;
	va_list args;

	va_start(args, f);
	done = vprintf(f, args);
	va_end(args);
	return done;
}