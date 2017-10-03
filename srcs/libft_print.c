/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erintala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:14:37 by erintala          #+#    #+#             */
/*   Updated: 2017/10/03 02:14:39 by erintala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

void	ft_putchar(t_printf *flags, int c)
{
	flags->length++;
	write(1, &c, 1);
}

void	ft_nputchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(t_printf *flags, char *s)
{
	while (*s)
	{
		ft_putchar(flags, *s);
		s++;
	}
}

void	ft_putnstr(t_printf *flags, char *s, int n)
{
	while (*s && n)
	{
		ft_putchar(flags, *s);
		s++;
		n--;
	}
}
