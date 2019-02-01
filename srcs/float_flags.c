/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:07:51 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/01 13:50:42 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_for_round(char *str, long double n)
{
	char		*new;
	long long	integer;

	n *= 10;
	if (n >= 5)
	{
		integer = ft_atoi(str);
		integer++;
		new = ft_llitoa(integer);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

char	*ft_check_float_flags(char *str, t_struct *p)
{
	char		*ret;

	ret = NULL;
	if (p->plus != 0 && str[0] != '-')
		ret = ft_put_char_at_start(str, '+');
	if (p->space != 0 && p->plus == 0)
		ret = ft_put_char_at_start(str, ' ');
	if (p->minus == 0 && p->zero != 0)
	{
		if (ret != NULL && p->width > ft_strlen(ret))
			ret = ft_fill_zeros_with_sign_float(ret, p);
		else if (str != NULL && (p->plus == 0 || str[0] == '-') &&
				p->width > ft_strlen(str))
			ret = ft_fill_zeros_with_sign_float(str, p);
	}
	if ((p->minus == 1 || p->width != 0) && ret != NULL)
		ret = ft_fill_width(ret, p);
	else if ((p->minus == 1 || p->width != 0) && str != NULL)
		ret = ft_fill_width(str, p);
	return (ret == NULL ? str : ret);
}

char	*ft_fill_zeros_with_sign_float(char *ret, t_struct *p)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = ft_strlen(ret);
	tmp = ft_create_str(p->width);
	if (ret[0] == '-' || ret[0] == '+')
	{
		tmp[0] = ret[0];
		j = 1;
		while (j < p->width - i + 1)
			tmp[j++] = '0';
		ft_strcpy(tmp + j, ret + 1);
		ft_strdel(&ret);
		return (tmp);
	}
	else
	{
		j = 0;
		while (j < p->width - i)
			tmp[j++] = '0';
	}
	ft_strcpy(tmp + j, ret);
	ft_strdel(&ret);
	return (tmp);
}
