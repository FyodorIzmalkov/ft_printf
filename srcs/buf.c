/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:51:30 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/24 20:23:57 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char_in_buff(t_struct *p, char c)
{
	char	*temp;
	char	*to_write;

	temp = p->buf;
	if (!(to_write = ft_memalloc(sizeof(char) * 2)))
		ft_malloc_error();
	to_write[0] = c;
	if (!(p->buf = ft_strjoin(p->buf, to_write)))
		ft_malloc_error();
	ft_strdel(&temp);
	ft_strdel(&to_write);
}

char	*ft_put_char_at_start(char *str, char c)
{
	char *new;
	size_t i;

	i = ft_strlen(str);
	if (!(new = ft_strnew(i)))
		ft_malloc_error();
	new[0] = c;
	ft_strcpy(new + 1, str);
	return (new);
}
