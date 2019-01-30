/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_oux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:35:27 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/30 22:59:20 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_oux(t_struct *p, va_list arg)
{
	char *temp;
	char *temp_buf;

	if (p->j == 1 || p->z == 1)
		return ;
	if (p->num == 0 && p->formatted == 0)
		p->num = va_arg(arg, unsigned int);
	if (p->str[p->i] == 'o' || p->str[p->i] == 'O')
		temp = ft_itoa_base(p->num, 8, 0);
	else if (p->str[p->i] == 'u' || p->str[p->i] == 'U')
		temp = ft_itoa_base(p->num, 10, 0);
	else if (p->str[p->i] == 'x')
		temp = ft_itoa_base(p->num, 16, 0);
	else if (p->str[p->i] == 'X')
		temp = ft_itoa_base(p->num, 16, 1);
	temp_buf = p->buf;
	if (p->minus != 0 || p->plus != 0 || p->space != 0 || p->zero != 0 ||
			p->dot != 0 || p->width != 0 || p->precision != 0 || p->sharp != 0)
		temp = ft_check_oux_flags(temp, p);
	if (!(p->buf = ft_strjoin(p->buf, temp)))
		ft_malloc_error();
	ft_strdel(&temp);
	ft_strdel(&temp_buf);
}
