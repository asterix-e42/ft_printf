/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 06:42:45 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/18 02:08:52 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"
#include "printf.h"

static int	debut(char *c, va_list va, t_data_printf *off)
{
	t_flag			*flag;
	static char		(*tabprintf[127])(va_list va, t_data_printf *, t_flag *);

	init(tabprintf);
	flag = new_flag(c);
	while (tabprintf[(int)*(flag->format)](va, off, flag))
		;
	return (flag->format - c + 1);
}

int			ft_printf(const char *format, ...)
{
	size_t			len;
	va_list			va;
	t_data_printf	*off;

	off = (void *)new_data();
	va_start(va, format);
	len = -1;
	while (*(++len + format) != '\0')
	{
		if (*(format + len) == '%')
			len += debut((char *)format + (len) + 1, va, off);
		else
			add_chr(*(len + format), off);
	}
	va_end(va);
	print(off, 1);
	return (off->size + off->tmp);
}
