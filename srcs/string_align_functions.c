/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_align_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:39:41 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/29 12:42:24 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_left_align_string(char *str, t_struct *p)
{
	size_t i;
	char *new;

	i = ft_strlen(str);
	if (!(new = ft_strnew(p->width)))
		ft_malloc_error();
	ft_strcpy(new, str);
	ft_strdel(&str);
	while (i < p->width)
		new[i++] = ' ';
	return (new);
}

char	*ft_fill_width(char *ret, t_struct *p)
{
	size_t i;

	i = ft_strlen(ret);
	if (i < p->width)
	{
		if (p->sharp == 1)
			ret = ft_check_sharp(ret, p);
		if (p->minus == 1)
		{
			ret = ft_left_align_string(ret, p);
			return (ret);
		}
		ret = ft_fill_it(ret, p);
		return (ret);
	}
	return (ret);
}

char	*ft_check_sign_precision(char *str, t_struct *p)
{
	char *new;
	size_t i;
	size_t j;
	char c;

	if (str[0] == '-' || str[0] == '+')
	{
		i = ft_strlen(str);
		i--;
		if (str[0] == '-')
			c = '-';
		else
			c = '+';
		if (!(new = ft_strnew(p->precision)))
			ft_malloc_error();
		j = 0;
		new[j++] = c;
		while (j <= p->precision - i)
			new[j++] = '0';
		ft_strcpy(new + j, str + 1);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}
			
char	*ft_fill_it(char *ret, t_struct *p)
{
	size_t i;
	size_t j;
	char *new;

	new = NULL;
	i = ft_strlen(ret);
	if (!(new = ft_strnew(p->width)))
		ft_malloc_error();
	j = 0;
	while (j < p->width - i)
		new[j++] = ' ';
	ft_strcpy(new + j, ret);
	ft_strdel(&ret);
	return (new);
}

char	*ft_check_sharp(char *ret, t_struct *p)
{
	if (p->str[p->i] == 'o')
	{
		ret = ft_check_sharp_o(ret, p);
		return (ret);
	}
	else if (p->str[p->i] == 'x' || p->str[p->i] == 'X')
	{
		ret = ft_check_sharp_x(ret, p);
		return (ret);
	}
	return (NULL);
}
