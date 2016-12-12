/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 06:42:45 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/12 02:24:02 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"
#include "printf.h"

static int	debut(const char *c, va_list va, t_list *off)
{
	if (*(c) == '%')
		add_chr('%', off);
	if (*(c) == 'c')
		add_chr(va_arg(va, int), off);
	if (*(c) == 's')
		add_str(va_arg(va, char *), off);
	if (*(c) == 'd')
		add_nbr(va_arg(va, int), off);
	if (*(c) == 'p')
		add_str("0x", off);
	if (*(c) == 'p')
		add_str(ft_itoabase((va_arg(va, long int)), "0123456789abcdef"), off);
	if (*(c) == 'C')
		stk_uni(va_arg(va, int), off);
	if (*(c) == 'S')
		uni_aff(va_arg(va, int*), off);
	return (2);
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
			debut(format + (++len), va, off);
		else
			add_chr(*(len + format), off);
	}
	va_end(va);
	return (0);
}
