/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:25:53 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/25 22:41:01 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_struct
{
	char	*buf;
	char	*str;
	int	i;
	size_t width;
	size_t precision;
	short	dot;
	int base;
	int sharp;
	int plus;
	int minus;
	int space;
	int zero;
	int fd;
	int perc_pos;
	int unicode;
	short j;
	short z;
	long double dbl;
	double flt;
	short is_ldouble;
	uintmax_t num;
	short digits;
}	t_struct;

//buf
void	ft_put_char_in_buff(t_struct *p, char c);
char	*ft_put_char_at_start(char *str, char c);
//conversion
void	ft_convert_str(t_struct *p, va_list arg);
void	ft_convert_di(t_struct *p, va_list arg);
void	ft_select_conversion(t_struct *p, va_list arg);
void	ft_convert_p(t_struct *p, va_list arg);
//conversion ouxX
void	ft_convert_ouxX(t_struct *p, va_list arg);
//ft_printf
void	ft_parce_until_percent(t_struct *p);
int		ft_printf(const char *format, ...);
//length_flags
void	ft_h_hh(t_struct *p, va_list arg);
void	ft_l_ll(t_struct *p, va_list arg);
void	ft_L(t_struct *p, va_list arg);
//struct
t_struct	*ft_make_struct(char *str);
void	ft_clean_struct(t_struct *p);
//check_flags
int	ft_check_pre_flag(char c);
int		ft_check_dot_and_digits(char c);
int		ft_check_length_flags(char c);
//conversion_c
void	ft_convert_c(t_struct *p, va_list arg);
char	*ft_left_align_c(char *dst, char c, size_t width, int left, t_struct *p);
//errors
void	ft_malloc_error(void);
void	ft_arg_error(void);
//ft_set
void	ft_set_digits(t_struct *p);
//parce
void	ft_get_flags(t_struct *p);
void	ft_get_width_and_precision(t_struct *p);
void	ft_get_length_flags(t_struct *p, va_list arg);
void	ft_parce_after_percent(t_struct *p, va_list arg);
void	ft_check_j_z(t_struct *p, va_list arg);
//itoa_base
void	itoa_base(uintmax_t val, unsigned int base, char *ret, int *i);
void	itoa_base1(uintmax_t val, unsigned int base, char *ret, int *i);
char	*ft_itoa_base(uintmax_t value, unsigned int base, int big);
char	*ft_left_align_p(char *ret, t_struct *p);
//conversion_f.c
void	ft_reverse(char *str, int len);
int		ft_int_to_str(long x, char *str, int d);
long	ft_power(long x, unsigned int y);
char	*ftoa(long double n, int point);
void	ft_convert_f(t_struct *p, va_list arg);
//conv_j_z
void	ft_conv_j(t_struct *p, va_list arg);
void	ft_conv_z(t_struct *p, va_list arg);
//precision_str.c
int		ft_check_str_flags(t_struct *p, char *str);
char	*ft_left_align_str(char *dst, char *src, size_t width, int left);
char	*ft_check_str_precision(t_struct *p, char *str);
// d_i_flags.c
char	*ft_check_di_flags(char *str, t_struct *p);
char	*ft_fill_zeros_with_sign(char *ret, t_struct *p);
char	*ft_fill_precision_di(char *ret, t_struct *p);
char	*ft_fill_width_di(char *ret, t_struct *p);
// string_align_functions.c
char	*ft_left_align_string(char *str, t_struct *p);
char	*ft_fill_width(char *ret, t_struct *p);
char	*ft_check_sign_precision(char *str, t_struct *p);
char	*ft_fill_it(char *ret, t_struct *p);
char	*ft_check_sharp(char *ret, t_struct *p);
// oux_flags.c
char	*ft_fill_precision_oux(char *ret, t_struct *p);
char	*ft_check_oux_flags(char *str, t_struct *p);
char	*ft_fill_zeros_without_sign(char *ret, t_struct *p);
char	*ft_check_sharp_o(char *ret, t_struct *p);
char	*ft_check_sharp_x(char *ret, t_struct *p);
#endif
