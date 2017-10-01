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
		ft_putchar(flags->pad_char);
		n--;
	}
}

int print_space(int n)
{
	while (n)
	{
		ft_putchar(' ');
		n--;
	}
	return (1);
}

int print_zero(int n)
{
	while (n)
	{
		ft_putchar('0');
		n--;
	}
	return (1); 
}

int print_prefix(char c)
{
	if (c == '+' || c == '-' || c == ' ')
		ft_putchar(c);
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
	int num_char;

	num_space = 0;
	num_char = 0;
	num_pad = 0;
	num_zero = 0;
	prefix = set_prefix(flags, i);
	num_digits = ft_countdigits(i);
	if (num_digits < flags->prec)
	{
		num_zero = flags->prec - num_digits;
		num_digits = flags->prec;
	}
	num_char = num_digits;
	if (prefix == '-' || prefix == '+' || prefix == ' ')
		num_digits++;
	if (num_digits < flags->width)
		num_space = flags->width - num_digits;
	if (flags->left)
	{
		print_prefix(prefix);
		print_zero(num_zero);
		ft_putnbr(i);
		print_space(num_space);
	}
	else 
	{
		if (flags->pad)
			print_zero(num_space);
		else
			print_space(num_space);
		print_prefix(prefix);
		print_zero(num_zero);
		ft_putnbr(i);
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
		ft_putnbr(i);
	return (1);
}

int print_u(t_printf *flags, unsigned long long i)
{
	int num_char;

	num_char = ft_ucountdigits(i);
	if (flags->is_int)
		i = (unsigned int)i;
	else if (flags->is_short)
		i = (unsigned short)i;
	else if (flags->is_char)
		i = (unsigned char)i;
	ft_uputnbr(i);
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
		ft_putnstr(s, num_char);
		pad_n(flags, flags->width);
	}
	else 
	{
		pad_n(flags, flags->width);
		ft_putnstr(s, num_char);
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
		ft_wputnstr(ws, num_char);
		pad_n(flags, flags->width);
	}
	else 
	{
		pad_n(flags, flags->width);
		ft_wputnstr(ws, num_char);
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
			ft_putchar(c);
			pad_n(flags, flags->width);
		}
		else
		{
			pad_n(flags, flags->width);
			ft_putchar(c);
		}
	}
	else
		ft_putchar(c);
	return (1);
}

int print_wc(t_printf *flags, wchar_t wc)
{
	if (flags->width > 1)
	{
		flags->width = flags->width - 1;
		if (flags->left == 1)
		{
			ft_wputchar(wc);
			pad_n(flags, flags->width);
		}
		else
		{
			pad_n(flags, flags->width);
			ft_wputchar(wc);
		}
	}
	else
		ft_wputchar(wc);
	return (1);
}

int print_x(unsigned long long int i)
{
	return (1);
}

int convert_p(t_printf *flags, va_list args)
{
	flags->alt = 1;
	convert_x(flags, args);
	return (1);
}

int convert_x(t_printf *flags, va_list args)
{
	unsigned long long int n = 1;
	char *s;
	// if (flags->alt == 1)
	// {}

	print_x(n);
	return (1);
}

int convert_u(t_printf *flags, va_list args)
{
	unsigned long long int u;

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
			ft_putstr("(null)");
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
		ft_putstr("(null)");
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
	set_width(f, flags, args);
	free(flags);
	return (1);
}

int vprintf(const char *f, va_list args)
{
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			if (set_flags(&f, args) == -1)
				return -1;
		}
		else
		{
			ft_putchar(*f);
			f++;
		}
	}
	return (1);
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