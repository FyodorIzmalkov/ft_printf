/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:26:09 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/30 20:07:04 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_strdel(char **str1, char **str2)
{
	if (str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2)
	{
		free(*str2);
		*str2 = NULL;
	}
}

void	ft_add_dog(t_struct *p)
{
	char *new;

	if (!(new = ft_strnew(2)))
		ft_malloc_error();
	new[0] = '^';
	new[1] = '@';
	p->dog++;
	p->width += 1;
	if (ft_check_str_flags(p, new) > 0)
		return ;
	if (!(p->buf = ft_strjoin(p->buf, new)))
		ft_malloc_error();
	free(new);
	new = NULL;
	return ;
}

void	ft_convert_c(t_struct *p, va_list arg)
{
	char	c;
	char	*new;

	if (p->num == 0)
		p->num = (unsigned char)va_arg(arg, uintmax_t);
	if (p->num == 0)
		return (ft_add_dog(p));
	c = p->num;
	if (p->width > 1)
	{
		if (!(new = ft_strnew(p->width)))
			ft_malloc_error();
		if (p->minus != 0)
		{
			ft_left_align_c(new, c, 1, p);
			return ;
		}
		ft_left_align_c(new, c, 0, p);
		return ;
	}
	ft_put_char_in_buff(p, c);
}

char	*ft_left_align_c(char *dst, char c, int left, t_struct *p)
{
	size_t	j;
	char	*temp;

	j = 0;
	temp = p->buf;
	if (left == 1)
	{
		dst[0] = c;
		while (++j < p->width)
			dst[j] = ' ';
		if (!(p->buf = ft_strjoin(p->buf, dst)))
			ft_malloc_error();
		ft_str_strdel(&temp, &dst);
	}
	if (left == 0)
	{
		while (j < p->width - 1)
			dst[j++] = ' ';
		dst[j] = c;
		if (!(p->buf = ft_strjoin(p->buf, dst)))
			ft_malloc_error();
		ft_str_strdel(&temp, &dst);
	}
	return (dst);
}
