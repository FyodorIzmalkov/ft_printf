/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:13:18 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/30 23:19:26 by lsandor-         ###   ########.fr       */
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
