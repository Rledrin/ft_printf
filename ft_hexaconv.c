/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:15:42 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/13 10:15:44 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_swap(char *a, char *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int					ft_dec2hex_up(unsigned int nb, char *str)
{
	char	*hex;
	int		i;
	int		j;

	i = 0;
	j = -1;
	hex = (char[17]){"0123456789ABCDEF"};
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (1);
	}
	while (nb > 0)
	{
		str[i++] = hex[nb % 16];
		nb /= 16;
	}
	str[i] = '\0';
	i--;
	while (j++ <= ((i / 2) - 1))
		ft_swap(&(str[j]), &(str[i - j]));
	return (i + 1);
}

int					ft_dec2hex_low(unsigned int nb, char *str)
{
	char	*hex;
	int		i;
	int		j;

	i = 0;
	j = -1;
	hex = (char[17]){"0123456789abcdef"};
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (1);
	}
	while (nb > 0)
	{
		str[i++] = hex[nb % 16];
		nb /= 16;
	}
	str[i] = '\0';
	i--;
	while (j++ <= ((i / 2) - 1))
		ft_swap(&(str[j]), &(str[i - j]));
	return (i + 1);
}

void				ft_print_hex2(t_tab *t, char *str, int len, int *variable)
{
	if (t->sign == 0 && t->space == 1)
		ft_putchar_fd_printf(t, ' ', 1);
	*variable = 0;
	if (t->min_len > t->precision && t->precision >= len)
		*variable = t->min_len - (t->precision + t->sign);
	else if (t->precision >= t->min_len && t->precision >= len)
		*variable = 0;
	else if (t->min_len > t->precision && len > t->precision)
		*variable = t->min_len - len - t->sign;
	if (t->precision > t->min_len)
	{
		ft_printchar(t, '0', (t->precision - len));
		ft_putstr_fd_printf(t, str, 1);
	}
}

void				ft_print_hex(t_tab *t, char *str, int len)
{
	int	variable;

	if (str[0] == '0' && t->precision == 0)
	{
		str[0] = '\0';
		len--;
	}
	ft_print_hex2(t, str, len, &variable);
	if (t->precision < 0 && t->zero == 1 && t->minus == 0)
	{
		ft_printchar(t, '0', (t->min_len - len - t->sign));
		ft_putstr_fd_printf(t, str, 1);
	}
	else if (t->min_len >= t->precision)
	{
		if (t->minus == 0)
			ft_printchar(t, ' ', (variable));
		ft_printchar(t, '0', (t->precision - len));
		ft_putstr_fd_printf(t, str, 1);
		if (t->minus == 1)
			ft_printchar(t, ' ', (variable));
	}
}
