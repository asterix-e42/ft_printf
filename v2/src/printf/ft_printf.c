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

char		def_flag_type(va_list va, t_data_printf *off, t_flag *flag)
{
	(void)va;
	(void)off;
	if (*(flag->format) == 'l')
		if (!((flag->flagtype) & FLAG_LONG))
			(flag->flagtype) = FLAG_LONG;
		else
			(flag->flagtype) = FLAG_LONGLONG;
	else if (*(flag->format) == 'h')
		if (!((flag->flagtype) & FLAG_SHORT))
			(flag->flagtype) = FLAG_SHORT;
		else
			(flag->flagtype) = FLAG_CHAR;
	else if (*(flag->format) == 'j')
		(flag->flagtype) = FLAG_MAX;
	else if (*(flag->format) == 'z')
		(flag->flagtype) = FLAG_SIZE_T;
	else
		ft_erreur("imposible");
	++(flag->format);
	return (1);
}

char		def_flag(va_list va, t_data_printf *off, t_flag *flag)
{
	(void)va;
	(void)off;
	if (*(flag->format) == '#')
		(flag->flagother) |= FLAG_DIESE;
	else if (*(flag->format) == 0)
		(flag->precision1) = atoistr(&(flag->format));
	else if (ft_isdigit(*(flag->format)))
		(flag->precision2) = atoistr(&(flag->format));
	else if (*(flag->format) == '.' && ++*(flag->format))
		(flag->precision3) = atoistr(&(flag->format));
	else if (*(flag->format) == '-')
		(flag->flagother) |= FLAG_MOIN;
	else if (*(flag->format) == '+')
		(flag->flagother) |= FLAG_PLUS;
	else if (*(flag->format) == ' ')
		(flag->flagother) |= FLAG_SPACE;
	else
		ft_erreur("imposibl");
	++(flag->format);
	return (1);
}

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
