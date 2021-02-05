/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:16:29 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/13 10:16:31 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		ft_check_str(t_tab *t)
{
	int		c;
	char	*str;

	if (t->type == 'c')
	{
		c = va_arg(t->ap, int);
		ft_print_char(t, c);
	}
	else if (t->type == 's')
	{
		str = va_arg(t->ap, char*);
		if (!str)
			str = (char[7]){"(null)"};
		ft_print_str(t, str);
	}
}

void		ft_print_str(t_tab *t, char *str)
{
	int len;
	int prec;

	len = ft_strlen(str);
	prec = t->precision;
	if (t->precision >= len && (t->min_len >= t->precision))
	{
		if ((t->min_len >= t->precision) && t->minus == 0)
			ft_printchar(t, ' ', (t->min_len - len));
		ft_putstr_fd_printf(t, str, 1);
		if ((t->min_len >= t->precision) && t->minus == 1)
			ft_printchar(t, ' ', (t->min_len - len));
	}
	else if (t->precision >= len && (t->min_len < t->precision))
	{
		if ((t->min_len < t->precision) && t->minus == 0)
			ft_printchar(t, ' ', (t->min_len - len));
		ft_putstr_fd_printf(t, str, 1);
		if ((t->min_len < t->precision) && t->minus == 1)
			ft_printchar(t, ' ', (t->min_len - len));
	}
	ft_print_str2(t, str, len, prec);
}

void		ft_print_str2(t_tab *t, char *str, int len, int prec)
{
	if (t->precision < len && prec == -1)
	{
		if ((t->min_len > t->precision) && t->minus == 0)
			ft_printchar(t, ' ', (t->min_len - (t->precision + 1) - len));
		ft_putstr_fd_printf(t, str, 1);
		if ((t->min_len > t->precision) && t->minus == 1)
			ft_printchar(t, ' ', (t->min_len - (t->precision + 1) - len));
	}
	else if (t->precision < len && t->precision >= 0)
	{
		if ((t->min_len > t->precision) && t->minus == 0)
			ft_printchar(t, ' ', (t->min_len - t->precision));
		while (prec-- > 0)
			ft_putchar_fd_printf(t, *str++, 1);
		if ((t->min_len > t->precision) && t->minus == 1)
			ft_printchar(t, ' ', (t->min_len - t->precision));
	}
}

void		ft_print_char(t_tab *t, int c)
{
	if (t->minus == 0)
		ft_printchar(t, ' ', (t->min_len - 1));
	write(1, &c, 1);
	if (t->minus == 1)
		ft_printchar(t, ' ', (t->min_len - 1));
	t->len += 1;
}
