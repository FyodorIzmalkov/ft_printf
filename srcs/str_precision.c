/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:43:35 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/26 14:10:02 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_str_flags(t_struct *p, char *str)
{
	char *new;
	char *tmp;

	if (ft_strlen(str) < p->width)
	{
		if (!(new = ft_strnew(p->width)))
			ft_malloc_error();
		tmp = p->buf;
		if (p->minus > 0)
		{
			ft_left_align_str(new, str, p->width, 1);
			if (!(p->buf = ft_strjoin(p->buf, new)))
				ft_malloc_error();
			ft_strdel(&tmp);
			ft_strdel(&new);
			return (1);
		}
		ft_left_align_str(new, str, p->width, 0);
		if (!(p->buf = ft_strjoin(p->buf, new)))
			ft_malloc_error();
		ft_strdel(&tmp);
		ft_strdel(&new);
		return (1);
	}
	return (-1);
}

char	*ft_left_align_str(char *dst, char *src, size_t width, int left)
{
	size_t i;
	size_t j;

	i = ft_strlen(src);
	j = 0;
	if (left == 1)
	{
		ft_strcpy(dst, src);
		while (i < width)
			dst[i++] = ' ';
	}
	if (left == 0)
	{
		while (j < width - i)
			dst[j++] = ' ';
		ft_strcpy(dst + j, src);
	}
	return (dst);
}

char	*ft_check_str_precision(t_struct *p, char *str)
{
	char	*new;
	if (p->dot != 0)
	{
		if (!(new = ft_strnew(p->precision)))
			ft_malloc_error();
		ft_strncpy(new, str, p->precision);
		return (new);
	}
	return (str);
}
