#include "../includes/ft_printf.h"
#include <locale.h>

const t_type g_dispatch_table[] = {
	{'s', convert_s},
	{'S', convert_ws},
	// {'p', convert_p},
	// {'d', convert_i},
	// {'D', },
	// {'i', convert_i},
	// {'o', },
	// {'O', },
	// {'u', },
	// {'U', },
	// {'x', convert_x},
	// {'X', },
	{'c', convert_c},
	{'C', convert_wc},
};

int print_info(t_printf *flags)
{
	printf("\nPRINT_INFO:\nprec: %i\nwidth: %i\nspec: %c\ntype: %i\nis_short: %i\nis_char: %i\nis_long: %i\nis_longlong: %i\nis_sizet: %i\nintmax: %i\nalt: %i\nspace: %i\nleft: %i\nshowsign: %i\nwide: %i\npad: %i\n", 
		flags->prec, flags->width, flags->spec, flags->type, flags->is_short,
		flags->is_char, flags->is_long, flags->is_longlong, flags->is_sizet, flags->intmax,
		flags->alt, flags->space, flags->left, flags->showsign, flags->wide,
		flags->pad);
	return (1);
}

void pad_char(t_printf *flags)
{
	int n;

	n = flags->width;
	while (n)
	{
		ft_putchar(flags->pad_char);
		n--;
	}
}

int print_s(t_printf *flags, char *s)
{
	int num_char;

	if (flags->width < flags->prec)
	{
		flags->width = 0;
		num_char = flags->prec;
	}
	else
	{
		num_char = ft_strlen(s);
		num_char = (flags->prec < num_char ? flags->prec : num_char);
		flags->width = (flags->width > num_char ? flags->width - num_char : flags->width - flags->prec);	
	}
	pad_char(flags);
	ft_putnstr(s, num_char);
	return (1);
}

int print_ws(t_printf *flags, wchar_t *ws)
{
	if (flags->alt == 1)
	{}
	ft_wputstr(ws);
	return 1;
}

int print_c(t_printf *flags, char c)
{
	if (flags->width > 1)
	{
		if (flags->left == 1)
		{
			ft_putchar(c);
			pad_char(flags);
		}
		else
		{
			pad_char(flags);
			ft_putchar(c);
		}
	}
	else
		ft_putchar(c);
	return (1);
}

int print_i(int n)
{
	ft_putnbr(n);
	return (1);
}

// int print_u(unsigned int n)
// {
	
// 	return (1);
// }

// int print_x(char *s)
// {
// 	ft_putstr(s);
// 	return (1);
// }

// int print_ud(unsigned int ud)
// {

// 	return (1);
// }

int print_wc(t_printf *flags, wchar_t wc)
{
	if (flags->width > 1)
	{
		if (flags->left == 1)
		{
			ft_wputchar(wc);
			pad_char(flags);
		}
		else
		{
			pad_char(flags);
			ft_wputchar(wc);
		}
	}
	else
		ft_wputchar(wc);
	return (1);
}

// int convert_ud(t_printf *flags, va_list args)
// {
// 	unsigned int ud;

// 	ud = va_arg(args, unsigned int);
// 	print_ud(ud);
// 	return (1);
// }

// int convert_p(t_printf *flags, va_list args)
// {
// 	flags->alt = 1;
// 	convert_x(flags, args);
// 	return (1);
// }

// int convert_x(t_printf *flags, va_list args)
// {
// 	unsigned int n;
// 	char *s;
// 	if (flags->alt == 1)
// 	{}

// 	print_x(s);
// 	return (1);
// }

// int convert_u(t_printf *flags, va_list args)
// {
// 	unsigned int n;

// 	n = va_arg(args, unsigned int);
// 	print_u(n);
// 	return (1);
// }

// int convert_i(t_printf *flags, va_list args)
// {
// 	int n;

// 	n = va_arg(args, int);
// 	return (print_i(n));	
// }

int convert_s(t_printf *flags, va_list args)
{
	char *s;

	if (flags->is_long == 1)
		convert_ws(flags, args);	
	else 
	{
		s = va_arg(args, char *);
		print_s(flags, s);
	}
	return (1);
}

int convert_ws(t_printf *flags, va_list args)
{
	wchar_t *ws;

	ws = va_arg(args, wchar_t *);
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

	if ((flags = (t_printf *)malloc(sizeof(t_printf))) == NULL)
		return NULL;
	flags->prec = 1;
	flags->width = 0;
	flags->spec = '0';
	flags->type = 0;
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
		(*f)++;
	else if (flags->is_char == 1 || flags->is_longlong == 1)
		(*f) += 2;
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
	}
	return (set_length(f, flags, args));
}

int set_width(const char **f, t_printf *flags, va_list args)
{
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
	//print_info(flags);
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

// int main(int argc, char **argv)
// {
// 	setlocale(LC_ALL, "en_US");
// 	printf("%1.s\n", "");
// 	ft_printf("%1.s\n", "");
// 	// while (1)
// 	// {}
// 	return (1);
// }