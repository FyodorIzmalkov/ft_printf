/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:03:46 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/25 19:42:03 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_h_hh(t_struct *p, va_list arg)
{
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i')
		p->num = (short int)va_arg(arg, uintmax_t);
	if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
			p->str[p->i] == 'X')
		p->num = (unsigned short int)va_arg(arg, uintmax_t);
	if (p->str[p->i] == 'h')
	{
		p->i++;
		if (p->str[p->i] == 'd' || p->str[p->i] == 'i')
			p->num = (char)va_arg(arg, uintmax_t);
		else if (p->str[p->i] == 'o' || p->str[p->i] == 'u' ||
				p->str[p->i] == 'x' || p->str[p->i] == 'X')
			p->num = (unsigned char)va_arg(arg, uintmax_t);
	}
}

void	ft_l_ll(t_struct *p, va_list arg)
{
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i')
		p->num = (long int)va_arg(arg, uintmax_t);
	if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
			p->str[p->i] == 'X')
		p->num = (unsigned long int)va_arg(arg, uintmax_t);
	if (p->str[p->i] == 'l')
	{
		p->i++;
		if (p->str[p->i] == 'd' || p->str[p->i] == 'i')
			p->num = (long long int)va_arg(arg, uintmax_t);
		if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
				p->str[p->i] == 'X')
			p->num = (unsigned long long int)va_arg(arg, uintmax_t);
	}
	if (p->str[p->i] == 'p')
		p->num = va_arg(arg, uintmax_t);
	else if (p->str[p->i] == 'c')
	{
		p->num = (wint_t)va_arg(arg, uintmax_t);
		p->unicode = 1;
	}
	else if (p->str[p->i] == 's')
		p->unicode = 1;
}

void	ft_L(t_struct *p, va_list arg)
{
	char	*temp;
	char	*temp_buf;

	if (p->str[p->i] == 'f')
	{
		p->is_ldouble = 1;
		p->dbl = (long double)va_arg(arg, long double);
		temp = ftoa(p->dbl, 6);
		temp_buf = p->buf;
		if (!(p->buf = ft_strjoin(p->buf, temp)))
			ft_malloc_error();
		ft_strdel(&temp);
		ft_strdel(&temp_buf);
	}
}
