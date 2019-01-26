/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:13:14 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/26 14:32:08 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fillstr(int len, char c)
{
	char *str;
	int i;

	if (!(str = ft_strnew(len)))
		ft_malloc_error();
	i = 0;
	while (i < len)
		str[i++] = c;
	return (str);
}

char	*ft_part_to_str(long long part, char *strint, int point)
{
	char *str;
	char *tmp;
	int part_len;

	if (!strint)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(strint) + point + 1)))
		ft_malloc_error();
	ft_strcat(str, strint);
	ft_strcat(str, ".");
	ft_strdel(&strint);
	tmp = ft_itoa_base(part, 10, 0);
	part_len = ft_strlen(tmp);
	if (point > part_len)
	{
		strint = ft_fillstr(point - part_len, '0');
		ft_strcat(str, strint);
		ft_strdel(&strint);
	}
	ft_strcat(str, tmp);
	ft_strdel(&tmp);
	return (str);
}

long	ft_power(long long x, unsigned int y)
{
	if (y == 0)
		return (1);
	else if (y % 2 == 0)
		return (ft_power(x, y / 2) * ft_power(x, y / 2));
	else
		return (x * ft_power(x, y / 2) * ft_power(x, y / 2));
}

char	*ft_ftoa(long double n, int point)
{
	long long ipart;
	char *str;
	char	*tmp;

	ipart = (long long)n;
	tmp = ft_llitoa(ipart);
	if (n < 0)
	{
		n = -n;
		ipart = -ipart;
	}
	n = (long double)(n - ipart);
	n = n * ft_power(10, point);
	ipart = (long long)n + (((n - (long long)n) >= 0.5) ? 1 : 0);
	if (point > 0)
		str = ft_part_to_str(ipart, tmp, point);
	else
		str = ft_check_for_round(tmp, n, ipart);
	return (str);
}


void	ft_convert_f(t_struct *p, va_list arg)
{
	char *temp;
	char *temp_buf;

	if (p->is_ldouble == 1)
		return ;
	p->flt = (double)va_arg(arg, double);
	if (p->dot == 1)
		temp = ft_ftoa(p->flt, p->precision);
	else
		temp = ft_ftoa(p->flt, 6);
	temp_buf = p->buf;
	if (!(p->buf = ft_strjoin(p->buf, temp)))
		ft_malloc_error();
	ft_strdel(&temp);
	ft_strdel(&temp_buf);
}
