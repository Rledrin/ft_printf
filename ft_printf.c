/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:16:04 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/13 10:16:05 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_tab	t;
	int		i;
	int		check;

	i = 0;
	t.len = 0;
	va_start(t.ap, format);
	t.format = (char*)format;
	ft_reset(&t);
	while (t.format[i] != '%' && t.format[i])
		ft_putchar_fd_printf(&t, t.format[i++], 1);
	while (t.format[i++])
	{
		check = 0;
		while (!t.type && t.format[i])
		{
			ft_type(ft_prec(ft_flags(&t, &i, &check), &i, &check), &i);
			i++;
		}
		ft_reset(ft_converse(&t));
		while (t.format[i] != '%' && t.format[i])
			ft_putchar_fd_printf(&t, t.format[i++], 1);
	}
	va_end(t.ap);
	return (t.len);
}

void		ft_percentage(t_tab *t)
{
	if (t->minus == 0 && t->zero == 0)
		ft_printchar(t, ' ', t->min_len - 1);
	else if (t->minus == 0 && t->zero == 1)
		ft_printchar(t, '0', t->min_len - 1);
	ft_putchar_fd_printf(t, '%', 1);
	if (t->minus == 1 && t->zero == 0)
		ft_printchar(t, ' ', t->min_len - 1);
	else if (t->minus == 1 && t->zero == 1)
		ft_printchar(t, ' ', t->min_len - 1);
}
