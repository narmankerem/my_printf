/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:17:20 by knarman           #+#    #+#             */
/*   Updated: 2023/12/22 16:51:08 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(const char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);
int	ft_puthexadecimal(unsigned int nb);
int	ft_puthexadecimal_upper(unsigned int nb);

#endif