/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:24:18 by lsandor-          #+#    #+#             */
/*   Updated: 2019/01/11 23:00:17 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int main()
{
	int i;
	int j;
	int k = 11;
	int l = 22;
	unsigned int x = 57820;
	intmax_t max = 123456780;
	char c = 'W';
	char *str = "HI IT'S STR AND I AM IN PRINTF && FT_PRINTF";
	long double lf = 123.123;
	float f = 100.100;

	ft_printf("----------START TEST---------\n");
	i = printf("___PRINTF: Hello world!\n");
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: Hello world!\n");
	printf("RET = %d\n", j);
	// string %s
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: %s\n", str);
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: %s\n", str);
	printf("RET = %d\n", j);
	// %
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: PRINT PERCENT = %%\n");
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: PRINT PERCENT = %%\n");
	printf("RET = %d\n", j);
	// c
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: PRINT C = %c\n", c);
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: PRINT C = %c\n", c);	
	printf("RET = %d\n", j);
	// i and d
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: PRINT i and d %i %d\n", k, l);
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: PRINT i and d %i %d\n", k, l);
	printf("RET = %d\n", j);
	//ouxX
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: PRINT o = %o, u = %u, x = %x, X = %X\n", x, x, x, x);
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: PRINT o = %o, u = %u, x = %x, X = %X\n", x, x, x, x);
	printf("RET = %d\n", j);
	// p
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: PRINTF &str = %p\n", &str);
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: PRINTF &str = %p\n", &str);
	printf("RET = %d\n", j);
	// Lf
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: PRINTF %%Lf = %Lf\n", lf);
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: PRINTF %%Lf = %Lf\n", lf);
	printf("RET = %d\n", j);
	// f
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: PRINTF %%f = %f\n", f);
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: PRINTF %%f = %f\n", f);
	printf("RET = %d\n", j);
	// j 
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: PRINTF %%jd = %jd\n", max);
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: PRINTF %%jd = %jd\n", max);
	printf("RET = %d\n", j);
	// z
	ft_printf("\n----------NEXT TEST----------\n");
	i = printf("___PRINTF: PRINTF %%zd = %zd\n", max);
	printf("RET = %d\n", i);
	j = ft_printf("FT_PRINTF: PRINTF %%zd = %zd\n", max);
	printf("RET = %d\n", j);
	ft_printf("\n----------NEXT TEST----------\n");
	return (0);
}
