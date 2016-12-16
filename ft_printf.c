/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 06:42:45 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/15 18:42:50 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"
#include "printf.h"

void def_flag(char **c, char *flag)
{
	char flagstp;
	flagstp = 1;
	--(*c);
	while (flagstp && *(++(*c)))
		if (**c == '#')
			*flag &= FLAG_DIESE;
		else if (**c == '0' || **c == '.')
			*flag &= FLAG_ZERO;
		else if (**c == '-')
			*flag &= FLAG_MOIN;
		else if (**c == '+')
			*flag &= FLAG_PLUS;
		else if (**c == ' ')
			*flag &= FLAG_SPACE;
		else
			flagstp = 0;
}

void def_flag_type(char **c, char *flag)
{
	char flagstp;
	flagstp = 1;
	--(*c);
	while (flagstp && *(++(*c)))
		if (**c == 'l' && *(*c + 1) == 'l' && ++(*c))
			*flag &= FLAG_LONGLONG;
		else if (**c == 'h' && *(*c + 1) == 'h' && ++(*c))
			*flag &= FLAG_CHAR;
		else if (**c == 'l')
			if (*flag & FLAG_LONGLONG)
				ft_erreur("tre");
			else
				*flag &= FLAG_LONG;
		else if (**c == 'h')
			if (*flag & FLAG_CHAR)
				ft_erreur("tre");
			else
				*flag &= FLAG_SHORT;
		else if (**c == 'j')
			*flag &= FLAG_MAX;
		else if (**c == 'z')
			*flag &= FLAG_SIZE_T;
		else
			flagstp = 0;
}



static int	debut(char *c, va_list va, t_list *off)
{
	char flag;
	char flag2;
	char *tmp;
	int precision;

	tmp = c;
	def_flag(&c, &flag);
	def_flag_type(&c, &flag2);
	precision = atoistr(&c);
	if (*(c) == '%')
		add_chr('%', off);
	if (*(c) == 'c')
		add_chr(va_arg(va, int), off);
	if (*(c) == 's')
		add_str(va_arg(va, char *), off);
	if (*(c) == 'd' || *(c) == 'i')
		add_nbr(va_arg(va, int), off);
	if (*(c) == 'p')
		add_str("0x", off);
	if (*(c) == 'x')
		add_str(ft_itoabaseint(va_arg(va, int), "0123456789abcdef"), off);
	if (*(c) == 'p' || (*(c) == 'l' && *(++c) == 'x'))
		add_str(ft_itoabase(va_arg(va, long int), "0123456789abcdef"), off);
	if (*(c) == 'X')
		add_str(ft_itoabaseint(va_arg(va, int), "0123456789ABCDEF"), off);
	if (*(c) == 'C')
		stk_uni(va_arg(va, int), off);
	if (*(c) == 'S')
		uni_aff(va_arg(va, int*), off);
	if (*(c) == 'D' || *(c) == 'u')
		add_nbr_unsigned(va_arg(va, unsigned int), off);
	return (c - tmp + 1);
}

int			ft_printf(const char *format, ...)
{
	size_t	len;
	va_list	va;
	t_list	*off;

	off = ft_lstnew("", BUFF_SIZE);
	off->content_size = 0;
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
	return (off->content_size);
}
