#include <unistd.h>
#include <wchar.h>
#include "../includes/ft_printf.h"

const char g_hex[] = {'a', 'b', 'c', 'd', 'e', 'f',
	 'A', 'B', 'C', 'D', 'E', 'F'};

size_t	ft_strlen(const char *str)
{
	size_t length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

int	ft_atoi(const char *str)
{
	int sign;
	int nbr;

	sign = 1;
	nbr = 0;
	if (*str == 0)
		return (0);
	while ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
		*str == '\f' || *str == '\r') && *str != 0)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57 && *str != 0)
	{
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	return (nbr * sign);
}

void ft_putchar(t_printf *flags, int c)
{
	flags->length++;
	write(1, &c, 1);
}

void ft_nputchar(int c)
{
	write(1, &c, 1);
}

void ft_putstr(t_printf *flags, char *s)
{
	while (*s)
	{
		ft_putchar(flags, *s);
		s++;
	}
}

void ft_putnstr(t_printf *flags, char *s, int n)
{
	while (*s && n)
	{
		ft_putchar(flags, *s);
		s++;
		n--;
	}
}

void ft_wputnstr(t_printf *flags, wchar_t *ws, int n)
{
	while (*ws && n)
	{
		ft_wputchar(flags, *ws);
		ws++;
		n--;
	}
}

int		ft_getdigits(unsigned long long int value, int base)
{
	int count;

	count = 0;
	while (value)
	{
		value /= base;
		count++;
	}
	return count;
}

void ft_itoa_base(t_printf *flags, unsigned long long int value, int base, int offset)
{
	char *str;
	int size;
	int i = 0;
	
	size = ft_getdigits(value, base);
	str = (char *)malloc(sizeof(char) * size + 1);
	i = size;
	str[i] = '\0';
	i--;
	while (value)
	{
		if (value % base > 9)
			str[i] = g_hex[value % base - 10 + offset];
		else
			str[i] = value % base + 48;
		value /= base;
		i--;
	}
	ft_putstr(flags, str);
	free(str);
}

void	ft_uputnbr(t_printf *flags, unsigned long long int i)
{
	if (i == 0)
	{
		ft_putchar(flags, '0');
		return ;
	}
	if (i / 10)
		ft_uputnbr(flags, i / 10);
	ft_putchar(flags, i % 10 + '0');
}

void	ft_putnbr(t_printf *flags, long long int i)
{
	if (i < 0)
	{
		if (i < -9223372036854775807)
		{
			ft_putnbr(flags, i / 10);
			ft_putchar(flags, '8');
			return ;
		}
		ft_putchar(flags, '-');
		i = -i;
	}
	if (i / 10)
		ft_putnbr(flags, i / 10);
	ft_putchar(flags, i % 10 + '0');
}

int ft_countdigits(long long int i)
{
	int count;

	count = 0;
	if (i < 0)
		i = -i;
	while (i)
	{
		i /= 10;
		count++;
	}
	return (count);
}

int ft_ucountdigits(unsigned long long int i)
{
	int count;

	count = 0;
	while (i)
	{
		i /= 10;
		count++;
	}
	return (count);	
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_wclen(wchar_t wc)
{
	if ((unsigned int)wc < 128)
		return (1);
	else if ((unsigned int)wc < 2048)
		return (2);
	else if ((unsigned int)wc < 65536)
		return (3);
	else
		return (4);
}

int		ft_wstrlen(wchar_t *ws)
{
	int len;

	len = 0;
	if (!ws)
		return (ft_strlen("(null)"));
	while (*ws)
	{
		len += ft_wclen(*ws);
		ws++;
	}
	return (len);
}

int		ft_wputstr(t_printf *flags, wchar_t *ws)
{
	while (*ws)
	{
		ft_wputchar(flags, *ws);
		ws++;
	}
	return (1);
}

int		ft_wputchar(t_printf *flags, wchar_t wc)
{
	if ((unsigned int)wc < 128)
		ft_putchar(flags, (unsigned int)wc);
	else if ((unsigned int)wc < 2048)
	{
		ft_putchar(flags, ((unsigned int)wc >> 6) | 192);
		ft_putchar(flags, ((unsigned int)wc & 63) | 128);
		return (2);
	}
	else if ((unsigned int)wc < 65536)
	{
		ft_putchar(flags, ((unsigned int)wc >> 12) | 224);
		ft_putchar(flags, (((unsigned int)wc >> 6) & 63) | 128);
		ft_putchar(flags, (((unsigned int)wc) & 63) | 128);
		return (3);
	}
	else
	{
		ft_putchar(flags, ((unsigned int)wc >> 18) | 240);
		ft_putchar(flags, (((unsigned int)wc >> 12) & 63) | 128);
		ft_putchar(flags, (((unsigned int)wc >> 6) & 63) | 128);
		ft_putchar(flags, ((unsigned int)wc & 63) | 128);
		return (4);
	}
	return (1);
}