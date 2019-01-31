/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:51:30 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/31 18:28:14 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char_in_buff(t_struct *p, char c)
{
	char	*temp;
	char	*to_write;

	temp = p->buf;
	if (!(to_write = ft_strnew(2)))
		ft_malloc_error();
	to_write[0] = c;
	if (c == '%')
		to_write = ft_align_percent(p, to_write);
	if (!(p->buf = ft_strjoin(p->buf, to_write)))
		ft_malloc_error();
	ft_strdel(&temp);
	ft_strdel(&to_write);
}

char	*ft_put_char_at_start(char *str, char c)
{
	char	*new;
	size_t	i;

	if (str[0] == '-')
		return (str);
	i = ft_strlen(str);
	if (!(new = ft_strnew(i)))
		ft_malloc_error();
	new[0] = c;
	ft_strcpy(new + 1, str);
	free(str);
	return (new);
}

char	*ft_return_single(char *str)
{
	char	*new;

	new = NULL;
	ft_strdel(&str);
	if (!(new = ft_strnew(1)))
		ft_malloc_error();
	return (new);
}
