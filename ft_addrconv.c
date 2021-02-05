/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:15:28 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/13 10:15:29 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dec2hex_low_po(long int nb, char *str)
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

void		ft_convp(t_tab *t)
{
	char	str[14];
	int		len;
	int		min_len;

	min_len = t->min_len;
	len = (ft_dec2hex_low_po(va_arg(t->ap, long int), str) + 2);
	if (t->minus == 0)
		ft_printchar(t, ' ', (min_len - len));
	ft_putstr_fd_printf(t, "0x", 1);
	ft_putstr_fd_printf(t, str, 1);
	if (t->minus == 1)
		ft_printchar(t, ' ', (min_len - len));
}
