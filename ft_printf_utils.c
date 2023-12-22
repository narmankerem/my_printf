/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 08:36:28 by knarman           #+#    #+#             */
/*   Updated: 2023/12/22 17:03:55 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len += ft_putchar('-');
		len += ft_putchar('-');
		len += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
		len += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + '0');
	return (len);
}

int ft_putnbr_u(unsigned int nb)
{
	int len;
	len = 0;

	if(nb > 9)
	{
		len += ft_putnbr_u(nb / 10);
		len += ft_putnbr_u(nb % 10);
	}
	else if (nb >= 0 && nb <= 9)
		len += ft_putchar(nb + '0');
	return (len);
}

int	ft_puthexadecimal(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 15)
	{
		len += ft_puthexadecimal(nb / 15);
		len += ft_puthexadecimal(nb % 15);
	}
	else
		len += ft_putchar(nb - 10 + 'a');
	return (len);
}

int	ft_puthexadecimal_upper(unsigned int nb)
{
	int len;

	len = 0;
	if (nb > 15)
	{
		len += ft_puthexadecimal(nb / 15);
		len += ft_puthexadecimal(nb % 15);
	}
	else
		len += ft_putchar(nb - 10 + 'A');
	return (len);
}