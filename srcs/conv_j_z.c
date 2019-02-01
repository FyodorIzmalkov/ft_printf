/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_j_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:15:55 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/01 18:28:32 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_j(t_struct *p, va_list arg)
{
	p->formatted = 1;
	if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
			p->str[p->i] == 'X' || p->str[p->i] == 'O' || p->str[p->i] == 'U')
	{
		p->num = (uintmax_t)va_arg(arg, uintmax_t);
	}
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i' || p->str[p->i] == 'D')
	{
		p->num = (intmax_t)va_arg(arg, intmax_t);
	}
	p->formatted = 1;
}

void	ft_conv_z(t_struct *p, va_list arg)
{
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i' || p->str[p->i] == 'D')
	{
		p->formatted = 1;
		p->num = va_arg(arg, ssize_t);
	}
	if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
			p->str[p->i] == 'X' || p->str[p->i] == 'O' || p->str[p->i] == 'U')
	{
		p->formatted = 1;
		p->num = (size_t)va_arg(arg, uintmax_t);
	}
}
