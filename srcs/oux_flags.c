/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:51:13 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/29 18:04:19 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill_precision_oux(char *ret, t_struct *p)
{
	char *new;
	size_t i;
	size_t j;

	i = ft_strlen(ret);
	if (p->precision == 0 && p->dot == 1)
		return (ft_strnew(1));
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
	char *ret;

	ret = NULL;
	if (p->sharp == 1 && p->num != 0)
		p->width -= 2;
	if (p->minus == 0 && p->zero != 0)
	{
		if (ret != NULL && p->width > ft_strlen(ret))
			ret = ft_fill_zeros_without_sign(ret, p);
		else if (str != NULL && (p->plus == 0 || str[0] == '-') &&
				p->width > ft_strlen(str))
			ret = ft_fill_zeros_without_sign(str, p);
	}
	if (p->dot == 1 && ret != NULL)
		ret = ft_fill_precision_oux(ret, p);
	else if (p->dot == 1 && str != NULL)
		ret = ft_fill_precision_oux(str, p);
	if	(p->width != 0 && ret != NULL)
		ret = ft_fill_width(ret, p);
	else if (p->width != 0 && str != NULL)
		ret = ft_fill_width(str, p);
	return (ret == NULL ? str : ret);
}

char	*ft_fill_zeros_without_sign(char *ret, t_struct *p)
{
	size_t i;
	size_t j;
	char *tmp;

	i = ft_strlen(ret);
	if (!(tmp = ft_strnew(p->width)))
		ft_malloc_error();
	j = 0;
	while (j < p->width - i && p->precision == 0)
		tmp[j++] = '0';
	ft_strcpy(tmp + j, ret);
	ft_strdel(&ret);
	return (tmp);
}

char	*ft_check_sharp_o(char *ret, t_struct *p)
{
	char *new;
	size_t z;
	size_t j = p->width;

	z = 0;
	new = NULL;
	j = 0;
	while (ret[z] != '\0' && ret[z] == '0')
		z++;
	if (z == 0)
		new = ft_put_char_at_start(ret, '0');
	return (new == NULL ? ret : new);
}

char	*ft_check_sharp_x(char *ret, t_struct *p)
{
	char *new;

	new = NULL;
	if (p->num != 0 && p->str[p->i] == 'x')
	{
		if (ft_check_ox(ret) == 1)
			return (ret);
		new = ft_put_char_at_start(ret, 'x');
		new = ft_put_char_at_start(new, '0');
		p->width +=2;
	}
	else if (p->num != 0 && p->str[p->i] == 'X')
	{
		if (ft_check_ox(ret) == 1)
			return (ret);
		new = ft_put_char_at_start(ret, 'X');
		new = ft_put_char_at_start(new, '0');
		p->width +=2;
	}
	return (new = NULL ? ret : new);
}
