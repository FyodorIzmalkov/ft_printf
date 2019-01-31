/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_ox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:21:01 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/31 22:48:07 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_ox(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
		{
			i++;
			if (str[i] == 'x' || str[i] == 'X')
				return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_sharp_zero_minus(char *str, t_struct *p)
{
	char	*new;
	char	c;
	size_t	i;
	size_t	len;

	i = 2;
	c = ' ';
	len = ft_strlen(str);
	new = ft_create_str(p->width);
	new[0] = '0';
	new[1] = 'x';
	if (p->zero == 1)
		c = '0';
	if (p->minus != 0)
	{
		ft_strcpy(new + 2, str);
		ft_strdel(&str);
		return (new);
	}
	while (i < p->width - len)
		new[i++] = c;
	ft_strcpy(new + i, str);
	ft_strdel(&str);
	return (new);
}

char	*ft_make_sharp(char *str, t_struct *p)
{
	char	*new;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	if ((p->zero == 1 || p->minus == 1) && p->dot == 0)
		return (ft_sharp_zero_minus(str, p));
	new = ft_create_str(p->width);
	while (i < p->width - len - 2)
		new[i++] = ' ';
	new[i++] = '0';
	new[i++] = 'x';
	ft_strcpy(new + i, str);
	ft_strdel(&str);
	return (new);
}
