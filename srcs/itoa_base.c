/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:37:41 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/24 19:23:10 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	itoa_base(intmax_t val, int base, char *ret, int *i)
{
	char base_str[] = "0123456789abcdef";

	if (val >= base)
		itoa_base(val/base, base, ret, i);
	ret[(*i)++] = base_str[val % base];
}

void	itoa_base1(intmax_t val, int base, char *ret, int *i)
{
	char base_str[] = "0123456789ABCDEF";

	if (val >= base)
		itoa_base1(val/base, base, ret, i);
	ret[(*i)++] = base_str[val % base];
}

char	*ft_left_align_p(char *ret, t_struct *p)
{
	char	*tmp;
	size_t i;
	size_t j;

	j = 0;
	if (ft_strlen(ret) < p->width)
	{
		if (!(tmp = ft_strnew(p->width)))
			ft_malloc_error();
		i = ft_strlen(ret);
		if (p->minus != 0)
		{
			ft_strcpy(tmp, ret);
			while (i < p->width)
				tmp[i++] = ' ';
			return (tmp);
		}
		while (j < p->width - i)
			tmp[j++] = ' ';
		ft_strcpy(tmp + j, ret);
		return (tmp);
	}
	return (ret);
}

char	*ft_itoa_base(intmax_t value, int base, int big)
{
	int i;
	intmax_t val;
	char *ret;

	val = value;
	i = 0;
	if (!(ret = ft_strnew(36)))
		ft_malloc_error();
	if (base == 10 && val < 0)
	{
		ret[i++] = '-';
		val = -val;
	}
	if (big == 0)
		itoa_base(val, base, ret, &i);
	if (big == 1)
		itoa_base1(val, base, ret, &i);
	if (big == 2)
	{
		ret[i++] = '0';
		ret[i++] = 'x';
		itoa_base(val, base, ret, &i);
	}
	return (ret);
}
