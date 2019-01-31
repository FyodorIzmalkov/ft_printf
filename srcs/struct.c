/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:29:54 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/31 22:57:52 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_make_struct(char *str)
{
	t_struct *p;

	if (!(p = ft_memalloc(sizeof(t_struct))))
		ft_malloc_error();
	if (!(p->buf = ft_memalloc(sizeof(char*))))
		ft_malloc_error();
	p->str = str;
	p->i = 0;
	p->fd = 1;
	return (p);
}

void		ft_clean_struct(t_struct *p)
{
	p->width = 0;
	p->precision = 0;
	p->dot = 0;
	p->base = 0;
	p->sharp = 0;
	p->plus = 0;
	p->minus = 0;
	p->space = 0;
	p->zero = 0;
	p->num = 0;
	p->unicode = 0;
	p->is_ldouble = 0;
	p->dbl = 0;
	p->flt = 0;
	p->j = 0;
	p->z = 0;
	p->formatted = 0;
}
