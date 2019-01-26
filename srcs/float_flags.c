/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:07:51 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/26 14:38:10 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_for_round(char *str, long double n)
{
	char *new;
	long long integer;

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
