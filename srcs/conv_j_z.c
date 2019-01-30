/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_j_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:15:55 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/30 18:17:46 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_j(t_struct *p, va_list arg)
{
	if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
			p->str[p->i] == 'X' || p->str[p->i] == 'O' || p->str[p->i] == 'U')
	{
		p->num = va_arg(arg, uintmax_t);
		ft_convert_oux(p, arg);
	}
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i' || p->str[p->i] == 'D')
	{
		p->num = va_arg(arg, intmax_t);
		ft_convert_di(p, arg);
	}
	p->j = 1;
}

void	ft_conv_z(t_struct *p, va_list arg)
{
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i' || p->str[p->i] == 'D')
	{
		p->formatted = 1;
		p->num = va_arg(arg, ssize_t);
		ft_convert_di(p, arg);
	}
	if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
			p->str[p->i] == 'X' || p->str[p->i] == 'O' || p->str[p->i] == 'U')
	{
		p->formatted = 1;
		ft_convert_oux(p, arg);
	}
	p->z = 1;
}
