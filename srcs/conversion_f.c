/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:13:14 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/26 12:20:36 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reverse(char *str, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int		ft_int_to_str(long x, char *str, int d)
{
	int i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	ft_reverse(str, i);
	str[i] = '\0';
	return (i);
}

long	ft_power(long x, unsigned int y)
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
	long ipart;
	long double fpart;
	int i;
	char *str;

	ipart = (long)n;
	fpart = n - (double)ipart;
	if (!(str = ft_strnew(50)))
		ft_malloc_error();
	i = ft_int_to_str(ipart, str, 0);
	if (point != 0)
	{
		str[i] = '.';
		fpart = fpart * ft_power(10, point);
		ft_int_to_str((long)fpart, str + i + 1, point);
	}
	return (str);
}


void	ft_convert_f(t_struct *p, va_list arg)
{
	char *temp;
	char *temp_buf;

	if (p->is_ldouble == 1)
		return ;
	p->flt = (double)va_arg(arg, double);
	temp = ftoa(p->flt, 6);
	temp_buf = p->buf;
	if (!(p->buf = ft_strjoin(p->buf, temp)))
		ft_malloc_error();
	ft_strdel(&temp);
	ft_strdel(&temp_buf);
}
