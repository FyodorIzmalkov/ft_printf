/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:39:31 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/31 21:43:20 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill_precision_di(char *ret, t_struct *p)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (p->precision == 0 && p->num == 0)
		return (ft_strnew(0));
	if ((ret[0] == '-' || ret[0] == '+' || ret[0] == ' ') && p->precision > 0)
	{
		ret = ft_check_sign_precision(ret, p);
		return (ret);
	}
	i = ft_strlen(ret);
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

char	*ft_check_di_flags(char *str, t_struct *p)
{
	if (p->plus != 0 && str[0] != '-')
		str = ft_put_char_at_start(str, '+');
	printf("0STR:%s\n",str);
	if (p->space != 0 && p->plus == 0)
		str = ft_put_char_at_start(str, ' ');
	printf("1STR:%s\n",str);
	if (p->minus == 0 && p->zero != 0)
	{
		if (p->width > ft_strlen(str))
			str = ft_fill_zeros_with_sign(str, p);
		else if ((p->plus == 0 || str[0] == '-') && p->width > ft_strlen(str))
			str = ft_fill_zeros_with_sign(str, p);
	}
	if (p->dot == 1)
		str = ft_fill_precision_di(str, p);
	if (p->minus == 1 || p->width != 0)
		str = ft_fill_width(str, p);
	return (str);
}

char	*ft_fill_zeros_with_sign(char *ret, t_struct *p)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = ft_strlen(ret);
	tmp = ft_create_str(p->width);
	if (ret[0] == '-' || ret[0] == '+' || ret[0] == ' ')
	{
		tmp[0] = ret[0];
		j = 1;
		while (j < p->width - i + 1 && p->precision == 0)
			tmp[j++] = '0';
		ft_strcpy(tmp + j, ret + 1);
		ft_strdel(&ret);
		return (tmp);
	}
	else
	{
		j = 0;
		while (j < p->width - i && p->precision == 0)
			tmp[j++] = '0';
	}
	ft_strcpy(tmp + j, ret);
	ft_strdel(&ret);
	return (tmp);
}
