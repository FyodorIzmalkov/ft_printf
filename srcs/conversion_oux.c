/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_oux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:35:27 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/01 18:25:44 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_oux(t_struct *p, va_list arg)
{
	char *temp;
	char *temp_buf;

	temp = NULL;
	if (p->num == 0 && p->str[p->i] == 'O' && p->formatted == 0)
		p->num = (unsigned long)va_arg(arg, uintmax_t);
	if (p->num == 0 && p->formatted == 0 && p->str[p->i] != 'O')
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
	if (ft_any_flag(p))
		temp = ft_check_oux_flags(temp, p);
	if (temp == NULL)
		temp = ft_return_sign(1, '0');
	if (!(p->buf = ft_strjoin(p->buf, temp)))
		ft_malloc_error();
	ft_str_strdel(&temp, &temp_buf);
}

int		ft_any_flag(t_struct *p)
{
	if (p->minus != 0 || p->plus != 0 || p->space != 0 || p->zero != 0 ||
		p->dot != 0 || p->width != 0 || p->precision != 0 || p->sharp != 0)
		return (1);
	return (0);
}
