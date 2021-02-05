/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:15:57 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/13 10:15:59 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset(t_tab *t)
{
	t->min_len = 0;
	t->minus = 0;
	t->zero = 0;
	t->precision = -1;
	t->type = 0;
	t->sign = 0;
	t->space = 0;
}

t_tab	*ft_flags(t_tab *t, int *i, int *check)
{
	char	*str;

	str = ft_strchr("-0", t->format[*i]);
	if (str)
	{
		if (*str == '-')
			t->minus = 1;
		else if (*str == '0' && t->format[*i - 1] != '.')
			t->zero = 1;
	}
	if (t->format[*i] == '.')
		*check = 1;
	if (t->format[*i] > '0' && t->format[*i] <= '9' && t->min_len == 0)
	{
		while (ft_isdigit(t->format[*i]) && *check == 0)
			t->min_len = t->min_len * 10 + t->format[(*i)++] - '0';
		*check = 1;
	}
	if (t->format[*i] == '*' && t->format[(*i) - 1] != '.')
	{
		t->min_len = va_arg(t->ap, int);
		ft_too_much_line(t);
	}
	return (t);
}

t_tab	*ft_prec(t_tab *t, int *i, int *check)
{
	if (t->format[*i] > '0' && t->format[*i] <= '9')
	{
		t->precision = 0;
		while (ft_isdigit(t->format[*i]))
		{
			t->precision = t->precision * 10 + t->format[*i] - '0';
			(*i)++;
		}
		(*i)--;
	}
	if (*check == 1 && !ft_isdigit(t->format[*i]) && t->format[(*i) - 1] == '.')
		t->precision = 0;
	if (t->format[*i] == '0' && t->format[(*i) - 1] == '.')
		t->precision = 0;
	if (t->precision == -1 && t->format[*i])
	{
		if (t->format[*i] == '.' && t->format[(*i) + 1] == '*')
		{
			t->precision = va_arg(t->ap, int);
			(*i)++;
			if (t->precision < -1)
				t->precision = -1;
		}
	}
	return (t);
}

void	ft_type(t_tab *t, int *i)
{
	if (t->format[*i] == 'c')
		t->type = 'c';
	else if (t->format[*i] == 's')
		t->type = 's';
	else if (t->format[*i] == 'd' || t->format[*i] == 'i')
		t->type = 'd';
	else if (t->format[*i] == 'p')
		t->type = 'p';
	else if (t->format[*i] == 'u')
		t->type = 'u';
	else if (t->format[*i] == 'x')
		t->type = 'x';
	else if (t->format[*i] == 'X')
		t->type = 'X';
	else if (t->format[*i] == '%' && !t->type)
		t->type = '%';
	else if (t->format[*i] == ' ')
		t->space = 1;
}
