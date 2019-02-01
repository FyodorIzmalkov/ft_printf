/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/01 17:22:07 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parce_until_percent(t_struct *p)
{
	while (p->str[p->i] != '\0' && p->str[p->i] != '%')
	{
		ft_put_char_in_buff(p, p->str[p->i]);
		p->i++;
	}
	if (p->str[p->i] == '%')
		p->perc_pos = p->i;
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	t_struct	*p;
	int			res;

	va_start(arg, format);
	p = ft_make_struct((char*)format);
	while (p->str[p->i] != '\0')
	{
		ft_parce_until_percent(p);
		if (p->str[p->i] == '\0')
			break ;
		p->i++;
		ft_parce_after_percent(p, arg);
		p->i++;
	}
	res = ft_strlen(p->buf);
	write(p->fd, p->buf, res);
	va_end(arg);
	res = ft_strlen(p->buf);
	free(p->buf);
	free(p);
	return (res);
}
