/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:13:18 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/01 18:10:23 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_make_string(const char *str)
{
	char	*new;
	size_t	i;

	i = ft_strlen(str);
	if (!(new = ft_strnew(i)))
		ft_malloc_error();
	ft_strcpy(new, str);
	return (new);
}

char	*ft_create_str(size_t len)
{
	char *new;

	if (!(new = ft_strnew(len)))
		ft_malloc_error();
	return (new);
}

char	*ft_return_sign(size_t len, char c)
{
	char *new;

	new = ft_create_str(len);
	new[0] = c;
	return (new);
}

char	*ft_check_for_returns(t_struct *p)
{
	if (p->space == 1)
		return (ft_return_sign(1, ' '));
	else if (p->plus == 1)
		return (ft_return_sign(1, '+'));
	else
		return (ft_strnew(0));
}

char	*ft_fill_precision_p(t_struct *p, char *str)
{
	size_t	i;
	char	*new;

	i = 0;
	if (str)
	{
		i = ft_strlen(str);
		i -= 2;
	}
	if (i < p->precision)
	{
		new = ft_create_str(p->precision + 2);
		new[0] = '0';
		new[1] = 'x';
		i = 2;
		while (p->precision + 2 > i + ft_strlen(str) - 2)
			new[i++] = '0';
		ft_strcpy(new + i, str + 2);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}
