/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:16:37 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/13 10:16:39 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char		*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		else
			str++;
	}
	return (str);
}

void		ft_printchar(t_tab *t, int c, int len)
{
	int		i;

	i = 0;
	if (len <= i)
		return ;
	while (i < len)
	{
		ft_putchar_fd_printf(t, c, 1);
		i++;
	}
}

void		ft_too_much_line(t_tab *t)
{
	if (t->min_len < 0)
	{
		t->min_len = -t->min_len;
		t->minus = 1;
	}
}

void		ft_check_hex(t_tab *t)
{
	char	str[15];
	int		len;

	len = 0;
	if (t->type == 'x')
	{
		len = ft_dec2hex_low(va_arg(t->ap, unsigned int), str);
		ft_print_hex(t, str, len);
	}
	else if (t->type == 'X')
	{
		len = ft_dec2hex_up(va_arg(t->ap, unsigned int), str);
		ft_print_hex(t, str, len);
	}
}
