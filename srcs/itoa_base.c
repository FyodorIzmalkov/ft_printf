/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:37:41 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/11 20:48:11 by lsandor-         ###   ########.fr       */
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
