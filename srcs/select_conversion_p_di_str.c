/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion_p_di_str.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:13:24 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/25 19:50:08 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_convert_str(t_struct *p, va_list arg)
{
	char	*arg_str;
	char	*temp;

	arg_str = va_arg(arg, char*);
	arg_str = ft_check_str_precision(p, arg_str);
	if (ft_check_str_flags(p, arg_str) > 0)
		return ;
	temp = p->buf;
	if (!(p->buf = ft_strjoin(p->buf, arg_str)))
		ft_malloc_error();
	ft_strdel(&temp);
}

void	ft_convert_di(t_struct *p, va_list arg)
{
	char *temp;
	char *ret;

	if (p->j == 1 || p->z == 1)
		return ;
	if (p->num == 0)
		p->num = (int)va_arg(arg, uintmax_t);
	temp = p->buf;
	if (!(ret = ft_itoa(p->num)))
		ft_malloc_error();
	if (p->minus != 0 || p->plus != 0 || p->space != 0 || p->zero != 0 || p->dot != 0 || p->width != 0 || p->precision != 0)
		ret = ft_check_di_flags(ret, p);
	if (!(p->buf = ft_strjoin(p->buf, ret)))
		ft_malloc_error();
	ft_strdel(&temp);
	ft_strdel(&ret);
}

void	ft_convert_p(t_struct *p, va_list arg)
{
	char *temp;
	char *temp_buf;

	temp_buf = p->buf;
	p->num = (unsigned long)va_arg(arg, void *);
	if (!(temp = ft_itoa_base(p->num, 16, 2)))
		ft_malloc_error();
	temp = ft_left_align_p(temp, p);
	if (!(p->buf = ft_strjoin(p->buf, temp)))
		ft_malloc_error();
	ft_strdel(&temp);
	ft_strdel(&temp_buf);
}

void	ft_select_conversion(t_struct *p, va_list arg)
{
	if (p->str[p->i] == '%')
		ft_put_char_in_buff(p, '%');
	if (p->str[p->i] == 'c' || p->str[p->i] == 'C')
		ft_convert_c(p, arg);
	if (p->str[p->i] == 'o' || p->str[p->i] == 'u' || p->str[p->i] == 'x' ||
			p->str[p->i] == 'X' || p->str[p->i] == 'O' || p->str[p->i] == 'U')
		ft_convert_ouxX(p, arg);
	if (p->str[p->i] == 's' || p->str[p->i] == 'S')
		ft_convert_str(p, arg);
	if (p->str[p->i] == 'd' || p->str[p->i] == 'i' || p->str[p->i] == 'D')
		ft_convert_di(p, arg);
	if (p->str[p->i] == 'p')
		ft_convert_p(p, arg);
	if (p->str[p->i] == 'f')
		ft_convert_f(p, arg);
}
