/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:20:38 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/01 16:09:37 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_malloc_error(void)
{
	ft_putstr_fd("error: Malloc allocation failed\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_arg_error(void)
{
	ft_putstr_fd("error: ARGS are invalid\n", 2);
	exit(EXIT_FAILURE);
}
