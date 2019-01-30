/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:40:48 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/30 20:08:01 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_pre_flag(char c)
{
	if (c == '#' || c == '0' || c == '+' || c == '-' || c == ' ')
		return (1);
	return (0);
}

int		ft_check_dot_and_digits(char c)
{
	if (ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}

int		ft_check_length_flags(char c)
{
	if (c == 'h' || c == 'l' || c == 'L' || c == 'z' || c == 'j')
		return (1);
	return (0);
}
