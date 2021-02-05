/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:15:50 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/13 10:15:51 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_comptage(unsigned int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void		ft_check_nbr(t_tab *t)
{
	int				nb;
	int				nb_len;
	unsigned int	nbu;

	nb_len = 0;
	nb = va_arg(t->ap, int);
	nbu = 0;
	if (nb < 0 && t->type == 'd')
	{
		t->sign = 1;
		if (nb == -2147483648)
		{
			nbu = 2147483648;
			nb_len = ft_comptage(nbu);
			ft_print_nbr(t, nbu, nb_len);
			return ;
		}
		nb = -nb;
		nb_len = ft_comptage(nb);
		ft_print_nbr(t, nb, nb_len);
		return ;
	}
	nb_len = ft_comptage((unsigned int)nb);
	ft_print_nbr(t, (unsigned int)nb, nb_len);
}

void		ft_print_nbr2(t_tab *t, unsigned int nb, int nblen, int *variable)
{
	int		check;

	check = 1;
	if (nb == 0 && t->precision == 0)
	{
		check = 0;
		nblen = 0;
	}
	if (t->sign == 0 && t->space == 1)
		ft_putchar_fd_printf(t, ' ', 1);
	*variable = 0;
	if (t->min_len > t->precision && t->precision >= nblen)
		*variable = t->min_len - (t->precision + t->sign);
	else if (t->precision >= t->min_len && t->precision >= nblen)
		*variable = 0;
	else if (t->min_len > t->precision && nblen > t->precision)
		*variable = t->min_len - nblen - t->sign;
	if (t->precision > t->min_len && check == 1)
	{
		ft_printchar(t, '0', (t->precision - nblen));
		ft_nbr_fd_u(t, nb, 1);
	}
}

void		ft_print_nbr(t_tab *t, unsigned int nb, int nb_len)
{
	int		variable;
	int		check;

	check = 1;
	if (nb == 0 && t->precision == 0)
		check = 0;
	if (nb == 0 && t->precision == 0)
		nb_len = 0;
	if (t->sign == 1 && t->precision > t->min_len)
		ft_putchar_fd_printf(t, '-', 1);
	ft_print_nbr2(t, nb, nb_len, &variable);
	if (t->precision < 0 && t->zero == 1 && t->minus == 0 && check == 1)
	{
		t->sign == 1 ? ft_putchar_fd_printf(t, '-', 1) : write(1, "", 0);
		ft_printchar(t, '0', (t->min_len - nb_len - t->sign));
		ft_nbr_fd_u(t, nb, 1);
	}
	else if (t->min_len >= t->precision)
	{
		ft_print_nbr3(t, variable, check, nb_len);
		if (check == 1)
			ft_nbr_fd_u(t, nb, 1);
		if (t->minus == 1)
			ft_printchar(t, ' ', (variable));
	}
}

void		ft_print_nbr3(t_tab *t, int variable, int check, int nb_len)
{
	if (t->minus == 0)
		ft_printchar(t, ' ', (variable));
	if (t->sign == 1)
		ft_putchar_fd_printf(t, '-', 1);
	if (check == 1)
		ft_printchar(t, '0', (t->precision - nb_len));
}
