/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_nbrprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erintala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:16:25 by erintala          #+#    #+#             */
/*   Updated: 2017/10/03 02:16:27 by erintala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	g_hex[] = {'a', 'b', 'c', 'd', 'e', 'f',
	'A', 'B', 'C', 'D', 'E', 'F'};

int		ft_atoi(const char *str)
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

void	ft_itoa_base(t_printf *flags, unsigned long long int value, int base,
	int offset)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
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
