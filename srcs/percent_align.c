/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_align.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:01:01 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/29 11:19:16 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_align_percent(t_struct *p, char *str)
{
	char *new;

	if (p->width != 0)
	{
		new = NULL;
		if (p->zero != 0 && p->minus == 0)
			new = ft_percent_zero(p, str);
		if (p->minus != 0)
			new = ft_left_align_string(str, p);
		if (new != NULL)
		{
			ft_strdel(&str);
			return (new);
		}
	}
	return (str);
}

char	*ft_percent_zero(t_struct *p, char *str)
{
	char *new;
	size_t i;
	size_t j;

	i = ft_strlen(str);
	if (p->width > i)
	{
		if (!(new = ft_strnew(p->width)))
			ft_malloc_error();
		j = 0;
		while (j < p->width - i)
			new[j++] = '0';
		ft_strcpy(new + j, str);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}
