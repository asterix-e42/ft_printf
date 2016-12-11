/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 06:42:45 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/12 00:08:41 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

#include<stdio.h>
#include<stdlib.h>

int debut(const char *c, va_list va)
{
	if (*(c + 1) == '%')
		write(1, "%", 1);
	if (*(c + 1) == 'c')
		ft_putchar(va_arg(va, int));
	if (*(c + 1) == 's')
		ft_putstr(va_arg(va, char *));
	if (*(c + 1) == 'd')
		ft_putnbr(va_arg(va, int));
	if (*(c + 1) == 'p')
		ft_putstr("0x");
	if (*(c + 1) == 'p')
		ft_putstr(ft_itoabase((va_arg(va,long int)), "0123456789abcdef"));
	return (2);
}

int ft_printf(const char * format, ...)
{
	size_t len;
	size_t start;
	va_list va;

	va_start(va, format);
	len = 0;
	start = 0;
	while (*(len + start + format) != '\0')
	{
		while (*(len + start + format) != '%' && *(len + start + format) != 0)
			++len;
		write(1, format + start, len);
		if (*(format + start + len) == '%')
			len += debut(format + start + len, va);
		start += len;
		len = 0;
	}
	va_end(va);
	return (0);
}


int main(void)
{
	char *a;
	int *ui;
//	int i = 51235;
	ui = (int *)malloc(12);
	a = (char *)malloc(1);
	ui = L"123";
	write(1, ui, 10);
	write(1, "i \n", 3);
ft_printf("gdf1g%%gg%c%d%s %d %p\n", 'a', 'a', "jhgfd", (int)a, a);
printf("%d %ud\n", 'c', L'c' - 'c' - 1);
return(-1 == printf("gdf1g%%gg%c%d%s %d %p i%Si %s\n", 'a', 'a', "jhgfd", (int)a, a, ui, "54"));
}
