/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:21:32 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/18 05:53:35 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	letre_s(va_list va, t_data_printf *off, t_flag *flag)
{
	char	*c;

	(void)flag;
	c = va_arg(va, char *);
	add_str(c, off);
	return (0);
}

char	letre_id(va_list va, t_data_printf *off, t_flag *flag)
{
	int		c;

	(void)flag;
	c = va_arg(va, int);
	add_nbr(c, off);
	return (0);
}

char	letre_x(va_list va, t_data_printf *off, t_flag *flag)
{
	int		c;
	char	*s;

	(void)flag;
	c = va_arg(va, int);
	s = ft_itoabaseint(c, "0123456789abcdef");
	add_str(s, off);
	return (0);
}
