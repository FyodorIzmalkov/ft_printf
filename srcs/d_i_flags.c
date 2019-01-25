/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:39:31 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/25 14:06:41 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_di_flags(char *str, t_struct *p)
{
	char *ret;

	ret = NULL;
	if (p->plus != 0 && str[0] != '-')
		ret = ft_put_char_at_start(str, '+');
	if (p->space != 0 && p->plus == 0 && str[0] != '-')
		ret = ft_put_char_at_start(str, ' ');
	if (ret != NULL && ((p->width > ft_strlen(ret)) || p->width > ft_strlen(str)) && p->minus == 0)
	{
		if (p->zero != 0 && ret != NULL)
			ret = ft_fill_zeros_with_sign(ret, p);
		if (p->zero != 0 && str != NULL && p->plus == 0)
			ret = ft_fill_zeros_with_sign(str, p);
	}
	return (ret);
}

char	*ft_fill_zeros_with_sign(char *ret, t_struct *p)
{
	size_t i;
	size_t j;
	char *tmp;

	i = ft_strlen(ret);
	if (!(tmp = ft_strnew(p->width)))
		ft_malloc_error();
	if (ret[0] == '-' || ret[0] == '+')
	{
		tmp[0] = ret[0];
		j = 1;
		while (j < p->width - i + 1)
			tmp[j++] = '0';
		ft_strcpy(tmp + j, ret + 1);
		return (tmp);
	}
	else
	{
		j = 0;
		while (j < p->width - i)
			tmp[j++] = '0';
	}
	ft_strcpy(tmp + j, ret);
	return (tmp);
}
