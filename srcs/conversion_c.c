/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:26:09 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/11 12:34:31 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_c(t_struct *p, va_list arg)
{
	char c;

	if (p->num == 0)
		p->num = (unsigned char)va_arg(arg, uintmax_t);
	c = p->num;
	ft_put_char_in_buff(p, c);
}
