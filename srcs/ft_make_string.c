/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:13:18 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/30 19:35:54 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_make_string(const char *str)
{
	char *new;
	size_t i;

	i = ft_strlen(str);
	if (!(new = ft_strnew(i)))
		ft_malloc_error();
	ft_strcpy(new, str);
	return (new);
}

void	ft_make_null(t_struct *p, char *str)
{
	char *new;
	size_t i;
	char *tmp;

	i = ft_strlen(str);
	if (!(new = ft_strnew(i)))
		ft_malloc_error();
	ft_strcpy(new, str);
	tmp = p->buf;
	if (!(new = ft_strjoin(p->buf, new)))
		ft_malloc_error();
	//if (tmp != NULL)
	//	ft_strdel(&tmp);
	free(new);
	new = NULL;
}
