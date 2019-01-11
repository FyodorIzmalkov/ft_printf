/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_ouxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:35:27 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/11 20:57:03 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_ouxX(t_struct *p, va_list arg)
{
	char *temp;
	char *temp_buf;

	if (p->num == 0)
		p->num = (unsigned int)va_arg(arg, uintmax_t);
	if (p->str[p->i] == 'o' || p->str[p->i] == 'O')
		temp = ft_itoa_base(p->num, 8, 0);
	else if (p->str[p->i] == 'u' || p->str[p->i] == 'U')
		temp = ft_itoa_base(p->num, 10, 0);
	else if (p->str[p->i] == 'x')
		temp = ft_itoa_base(p->num, 16, 0);
	else if (p->str[p->i] == 'X')
		temp = ft_itoa_base(p->num, 16, 1);
	temp_buf = p->buf;
	if (!(p->buf = ft_strjoin(p->buf, temp)))
		ft_malloc_error();
	ft_strdel(&temp);
	ft_strdel(&temp_buf);
}
