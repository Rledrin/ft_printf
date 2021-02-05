/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:15:35 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/13 10:15:37 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_converse(t_tab *t)
{
	if (t->type == 'c' || t->type == 's')
		ft_check_str(t);
	else if (t->type == 'd' || t->type == 'u')
		ft_check_nbr(t);
	else if (t->type == 'p')
		ft_convp(t);
	else if (t->type == 'X' || t->type == 'x')
		ft_check_hex(t);
	else if (t->type == '%')
		ft_percentage(t);
	return (t);
}

void	ft_nbr_fd_u(t_tab *t, unsigned int u, int fd)
{
	if (u >= 10)
	{
		ft_nbr_fd_u(t, u / 10, fd);
		ft_putchar_fd_printf(t, u % 10 + '0', fd);
	}
	else
		ft_putchar_fd_printf(t, u + '0', fd);
}

void	ft_putstr_fd_printf(t_tab *t, char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd_printf(t, s[i], fd);
		i++;
	}
}

void	ft_putchar_fd_printf(t_tab *t, char c, int fd)
{
	write(fd, &c, 1);
	t->len += 1;
}
