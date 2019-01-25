/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:34:16 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/25 19:49:44 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_itoa_len(long long int n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(long long int n)
{
	char			*ret;
	size_t			len;
	long long int	temp;

	len = ft_itoa_len(n);
	temp = n;
	if (n < 0)
	{
		temp = -n;
		len++;
	}
	if (!(ret = ft_strnew(len)))
		return (NULL);
	ret[--len] = temp % 10 + '0';
	while (temp /= 10)
		ret[--len] = temp % 10 + '0';
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
