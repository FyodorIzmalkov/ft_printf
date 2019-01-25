/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:37:30 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/25 19:43:47 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_flags(t_struct *p)
{
	while (ft_check_pre_flag(p->str[p->i]))
	{
		if (p->str[p->i] == '#')
			p->sharp = 1;
		else if (p->str[p->i] == '0')
			p->zero = 1;
		else if (p->str[p->i] == ' ')
			p->space = 1;
		else if (p->str[p->i] == '+')
			p->plus = 1;
		else if (p->str[p->i] == '-')
			p->minus = 1;
		p->i++;
	}
}

void	ft_get_width_and_precision(t_struct *p)
{
	while (ft_check_dot_and_digits(p->str[p->i]))
	{
		if (p->str[p->i] == '.')
		{
			p->dot = 1;
			p->i++;
			continue ;
		}
		else if (p->dot == 1)
		{	
			p->precision = (p->precision * 10) + (p->str[p->i] - '0');
			p->i++;
			continue ;
		}
		else
			p->width = (p->width * 10) + (p->str[p->i] - '0');
		p->i++;
	}
}

void	ft_get_length_flags(t_struct *p, va_list arg)
{
	if (ft_check_length_flags(p->str[p->i]))
	{
		if (p->str[p->i] == 'h')
		{
			p->i++;
			ft_h_hh(p, arg);
		}
		else if (p->str[p->i] == 'l')
		{
			p->i++;
			ft_l_ll(p, arg);
		}
		else if (p->str[p->i] == 'L')
		{
			p->i++;
			ft_L(p, arg);
		}
	}
}

void	ft_check_j_z(t_struct *p, va_list arg)
{
	if (ft_check_length_flags(p->str[p->i]))
	{
		if (p->str[p->i] == 'j')
		{
			p->i++;
			ft_conv_j(p, arg);
		}
		else if (p->str[p->i] == 'z')
		{
			p->i++;
			ft_conv_z(p, arg);
		}
	}
}

void	ft_parce_after_percent(t_struct *p, va_list arg)
{
	ft_clean_struct(p);
	ft_get_flags(p);
	ft_get_width_and_precision(p);
	ft_get_length_flags(p, arg);
	ft_check_j_z(p, arg);
	ft_select_conversion(p, arg);
}
