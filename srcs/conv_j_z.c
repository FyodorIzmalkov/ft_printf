/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_j_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:15:55 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/11 22:55:00 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_j(t_struct *p, va_list arg)
{
	if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
			p->str[p->i] == 'X' || p->str[p->i] == 'O' || p->str[p->i] == 'U')
		ft_convert_ouxX(p, arg);
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i' || p->str[p->i] == 'D')
		ft_convert_di(p, arg);
	p->j = 1;
}

void	ft_conv_z(t_struct *p, va_list arg)
{
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i' || p->str[p->i] == 'D')
		ft_convert_di(p, arg);
	if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
			p->str[p->i] == 'X' || p->str[p->i] == 'O' || p->str[p->i] == 'U')
		ft_convert_ouxX(p, arg);
	p->z = 1;
}
