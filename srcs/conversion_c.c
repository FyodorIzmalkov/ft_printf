/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:26:09 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/24 16:16:10 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_c(t_struct *p, va_list arg)
{
	char c;
	char	*new;

	if (p->num == 0)
		p->num = (unsigned char)va_arg(arg, uintmax_t);
	c = p->num;
	if (p->width > 1)
	{
		if (!(new = ft_strnew(p->width)))
			ft_malloc_error();
		if (p->minus != 0)
		{
			ft_left_align_c(new, c, p->width, 1, p);
			return ;
		}
		ft_left_align_c(new, c, p->width, 0, p);
		return ;
	}
	ft_put_char_in_buff(p, c);
}

char	*ft_left_align_c(char *dst, char c, size_t width, int left, t_struct *p)
{
	size_t j;
	char *temp;

	j = 0;
	temp = p->buf;
	if (left == 1)
	{
		dst[0] = c;
		while (++j < width)
			dst[j] = ' ';
		if (!(p->buf = ft_strjoin(p->buf, dst)))
			ft_malloc_error();
		ft_strdel(&temp);
		ft_strdel(&dst);
	}
	if (left == 0)
	{
		while (j < width - 1)
			dst[j++] = ' ';
		dst[j] = c;
		if (!(p->buf = ft_strjoin(p->buf, dst)))
			ft_malloc_error();
		ft_strdel(&temp);
		ft_strdel(&dst);
	}
	return (dst);
}
