/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:16:20 by rledrin           #+#    #+#             */
/*   Updated: 2019/11/13 10:16:21 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_tab
{
	va_list			ap;
	int				len;
	int				min_len;
	int				precision;
	char			*format;
	int				minus;
	int				zero;
	char			type;
	int				sign;
	int				space;
}					t_tab;

void				ft_reset(t_tab *t);
t_tab				*ft_flags(t_tab *t, int *i, int *check);
t_tab				*ft_prec(t_tab *t, int *i, int *check);
void				ft_type(t_tab *t, int *i);
void				ft_check_nbr(t_tab *t);
void				ft_check_hex(t_tab *t);
void				ft_print_hex(t_tab *t, char *str, int len);
void				ft_print_hex2(t_tab *t, char *str, int len, int *variable);
int					ft_dec2hex_up(unsigned int nb, char *str);
void				ft_print_nbr2(t_tab *t, unsigned int nb, int nl, int *var);
int					ft_dec2hex_low_po(long int nb, char *str);
int					ft_dec2hex_low(unsigned int nb, char *str);
void				ft_print_nbr(t_tab *t, unsigned int nb, int nb_len);
void				ft_print_nbr3(t_tab *t, int var, int check, int nb_len);
void				ft_printchar(t_tab *t, int c, int len);
void				ft_print_num(t_tab *t);
t_tab				*ft_converse(t_tab *t);
int					ft_comptage(unsigned int nb);
void				ft_convp(t_tab *t);
void				ft_swap(char *a, char *b);
void				ft_check_str(t_tab *t);
void				ft_print_str(t_tab *t, char *str);
void				ft_print_str2(t_tab *t, char *str, int len, int prec);
void				ft_print_char(t_tab *t, int c);
void				ft_percentage(t_tab *t);
void				ft_nbr_fd_u(t_tab *t, unsigned int u, int fd);
void				ft_putstr_fd_printf(t_tab *t, char *s, int fd);
void				ft_putchar_fd_printf(t_tab *t, char c, int fd);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_isdigit(int c);
void				ft_too_much_line(t_tab *t);
int					ft_printf(const char *format, ...);

#endif
