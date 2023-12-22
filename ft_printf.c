/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 08:18:39 by knarman           #+#    #+#             */
/*   Updated: 2023/12/22 17:05:55 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return ("NULL");
	while (*s)
	{
		len += write(1, &(*s++), 1);
	}
	return (len);
}

int	check(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x')
		return (ft_puthexadecimal(va_arg(args, unsigned long long int)));
	else if (c == 'X')
		return (ft_puthexadecimal_upper(va_arg(args, unsigned long long int)));
	else if (c == 'P')
	{
		write(1, "0x", 2);
		return (ft_puthexadecimal(va_arg(args, unsigned long long int)) + 2);
	}
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
	{
		return (ft_putnbr(va_arg(args, int)));
	}
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += check(str[i], args);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	return (len);
	va_end(args);
}
