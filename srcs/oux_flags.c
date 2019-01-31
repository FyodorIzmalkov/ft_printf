/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:51:13 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/31 19:03:15 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill_precision_oux(char *ret, t_struct *p)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = ft_strlen(ret);
	if (p->precision == 0 && p->dot == 1 && (p->str[p->i] == 'x' ||
				p->str[p->i] == 'X'))
		return (ft_return_single(ret));
	else if (p->precision == 0 && p->dot == 1 && p->str[p->i] == 'o' &&
			p->sharp == 0)
		return (ft_return_single(ret));
	if (i < p->precision)
	{
		if (!(new = ft_strnew(p->precision)))
			ft_malloc_error();
		j = 0;
		while (j < p->precision - i)
			new[j++] = '0';
		ft_strcpy(new + j, ret);
		ft_strdel(&ret);
		return (new);
	}
	return (ret);
}

char	*ft_check_oux_flags(char *str, t_struct *p)
{
	if (p->sharp == 1)
		str = ft_check_sharp(str, p);
	if (p->minus == 0 && p->zero != 0)
	{
		if (p->width > ft_strlen(str))
			str = ft_fill_zeros_without_sign(str, p);
		else if ((p->plus == 0 || str[0] == '-') && p->width > ft_strlen(str))
			str = ft_fill_zeros_without_sign(str, p);
	}
	if (p->dot == 1)
		str = ft_fill_precision_oux(str, p);
	if (p->width != 0)
		str = ft_fill_width(str, p);
	return (str);
}

char	*ft_fill_zeros_without_sign(char *ret, t_struct *p)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = ft_strlen(ret);
	tmp = ft_create_str(p->width);
	j = 0;
	while (j < p->width - i && p->precision == 0)
		tmp[j++] = '0';
	ft_strcpy(tmp + j, ret);
	ft_strdel(&ret);
	return (tmp);
}

char	*ft_check_sharp_o(char *ret)
{
	size_t	z;
	size_t	j;

	z = 0;
	j = 0;
	while (ret[z] != '\0' && ret[z] == '0')
		z++;
	if (z == 0)
		ret = ft_put_char_at_start(ret, '0');
	return (ret);
}

char	*ft_check_sharp_x(char *ret, t_struct *p)
{

	if (p->num != 0)
	{
		if (ft_strlen(ret) < p->width)
			return (ft_make_sharp(ret, p));
		if (ft_check_ox(ret) == 1)
			return (ret);
		if (p->str[p->i] == 'x')
			ret = ft_put_char_at_start(ret, 'x');
		else if (p->str[p->i] == 'X')
			ret = ft_put_char_at_start(ret, 'X');
		ret = ft_put_char_at_start(ret, '0');
		p->width += 2;
	}
	return (ret);
}
