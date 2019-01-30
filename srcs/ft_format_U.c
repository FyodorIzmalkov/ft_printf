/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_U.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:23:20 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/30 15:28:18 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_u(t_struct *p, va_list arg)
{
	p->formatted = 1;
	p->num = (unsigned long)va_arg(arg, uintmax_t);
	ft_convert_ouxX(p, arg);
}
