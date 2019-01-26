/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llitoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:29:55 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/26 13:12:43 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_digits(long long int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		++len;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

void		ft_inner_itoa(long long int n, size_t len, char *buf)
{
	char	*ptr;

	ptr = buf;
	while (len)
	{
		ptr[len - 1] = n % 10 + '0';
		n /= 10;
		--len;
	}
}

char			*ft_llitoa(long long int n)
{
	char			*newstr;
	size_t			len;
	int				sign;

	sign = n >= (long long)0 ? 0 : 1;
	len = ft_digits(n);
	if (n == 0)
		len = 1;
	if (!(newstr = ft_strnew(len)))
		ft_malloc_error();
	if (n < -9223372036854775807)
	{
		ft_strcpy(newstr, "-9223372036854775808");
		return (newstr);
	}
	if (sign)
		n *= -1;
	ft_inner_itoa(n, len, newstr);
	if (sign)
		newstr[0] = '-';
	newstr[len] = '\0';
	return (newstr);
}
