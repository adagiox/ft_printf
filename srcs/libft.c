#include <unistd.h>
#include <wchar.h>
#include "../includes/ft_printf.h"

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

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void ft_putnstr(char *s, int n)
{
	while (*s && n)
	{
		ft_putchar(*s);
		s++;
		n--;
	}
}

void	ft_putnbr(int n)
{
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr(n / 10);
			ft_putchar('8');
			return ;
		}
		ft_putchar('-');
		n = -n;
	}
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_wclen(wchar_t wc)
{
	if ((unsigned int)wc < ONE_BYTE)
		return (1);
	else if ((unsigned int)wc < TWO_BYTE)
		return (2);
	else if ((unsigned int)wc < THREE_BYTE)
		return (3);
	else
		return (4);
}

int		ft_wstrlen(wchar_t *ws)
{
	int	len;

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

int		ft_wputstr(wchar_t *ws)
{
	int len;

	len = 0;
	while (*ws)
	{
		len += ft_wputchar(*ws);
		ws++;
	}
	return (len);
}

int		ft_wputchar(wchar_t wc)
{
	if ((unsigned int)wc < ONE_BYTE)
		ft_putchar((unsigned int)wc);
	else if ((unsigned int)wc < TWO_BYTE)
	{
		ft_putchar(((unsigned int)wc >> 6) | 192);
		ft_putchar(((unsigned int)wc & 63) | 128);
		return (2);
	}
	else if ((unsigned int)wc < THREE_BYTE)
	{
		ft_putchar(((unsigned int)wc >> 12) | 224);
		ft_putchar((((unsigned int)wc >> 6) & 63) | 128);
		ft_putchar((((unsigned int)wc) & 63) | 128);
		return (3);
	}
	else
	{
		ft_putchar(((unsigned int)wc >> 18) | 240);
		ft_putchar((((unsigned int)wc >> 12) & 63) | 128);
		ft_putchar((((unsigned int)wc >> 6) & 63) | 128);
		ft_putchar(((unsigned int)wc & 63) | 128);
		return (4);
	}
	return (1);
}