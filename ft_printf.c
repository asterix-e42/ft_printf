/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 06:42:45 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/20 09:13:40 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"
#include "printf.h"

int def_flag_type(char **c, char *flag)
{
	char flagstp;
	flagstp = 1;
	while (flagstp && *(++(*c)))
		if (**c == 'l')
			if (!(*flag & FLAG_LONG))
				*flag |= FLAG_LONG;
			else
				*flag |= FLAG_LONGLONG;
		else if (**c == 'h')
			if (!(*flag & FLAG_SHORT))
				*flag |= FLAG_SHORT;
			else
				*flag |= FLAG_CHAR;
		else if (**c == 'j')
			*flag |= FLAG_MAX;
		else if (**c == 'z')
			*flag |= FLAG_SIZE_T;
		else
		{
			flagstp = 0;
			return(1);
		}
	return(0);
}

void def_flag(char **c, char *flag, int *size, int *prec)
{
	char flagstp;

	flagstp = 1;
	--(*c);
	while (flagstp)
		if (def_flag_type(c, flag + 1))
		{
			if (**c == '#')
				*flag |= FLAG_DIESE;
			else if (ft_isdigit(**c) || (**c == '.' && *prec == 0 && *(++(*c))))
				*size = atoistr(c);
			else if ((**c == '0' || **c == '.') && *(++(*c)))
				*prec = atoistr(&(*c));
			else if (**c == '-')
				*flag |= FLAG_MOIN;
			else if (**c == '+')
				*flag |= FLAG_PLUS;
			else if (**c == ' ')
				*flag |= FLAG_SPACE;
			else
				flagstp = 0;
		}
}

static int	debut(char *c, va_list va, t_list *off)
{
	char	flag[2];
	char	*tmp;
	int		size;
	int		precision;

	*flag = 0;
	flag[1] = 0;
	precision = 0;
	tmp = c;
	def_flag(&c, flag, &size, &precision);
	if (*(c) == '%')
		add_chr('%', off);
	else if (*(c) == 'c')
		add_chr(va_arg(va, int), off);
	else if (*(c) == 's')
		add_str(va_arg(va, char *), off);
	else if (*(c) == 'd' || *(c) == 'i')
		add_nbr(va_arg(va, int), off);
	else if (*(c) == 'x')
		add_str(ft_itoabaseint(va_arg(va, int), "0123456789abcdef"), off);
	else if (*(c) == 'p')
	{
		add_str("0x", off);
		add_str(ft_itoabase(va_arg(va, long int), "0123456789abcdef"), off);
	}
	else if (*(c) == 'X')
		add_str(ft_itoabaseint(va_arg(va, int), "0123456789ABCDEF"), off);
	else if (*(c) == 'o' || *(c) == 'O')
		add_str(ft_itoabaseint(va_arg(va, int), "01234567"), off);
	else if (*(c) == 'C')
		stk_uni(va_arg(va, int), off);
	else if (*(c) == 'S')
		uni_aff(va_arg(va, int*), off);
	else if (*(c) == 'D' || *(c) == 'u')
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
	print(off, 1);
	return (off->content_size + off->size_tmp);
}
