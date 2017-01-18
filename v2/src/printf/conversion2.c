/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:21:32 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/17 21:48:25 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	letre_p(va_list va, t_data_printf *off, t_flag *flag)
{
	long int		c;
	char			*s;

	(void)flag;
	c = va_arg(va, long int);
	add_str("0x", off);
	s = ft_itoabase(c, "0123456789abcdef");
	add_str(s, off);
	return (0);
}

char	letre_mx(va_list va, t_data_printf *off, t_flag *flag)
{
	int				c;
	char			*s;

	(void)flag;
	c = va_arg(va, int);
	s = ft_itoabaseint(c, "0123456789abcdef");
	add_str(s, off);
	return (0);
}

char	letre_moo(va_list va, t_data_printf *off, t_flag *flag)
{
	int				c;
	char			*s;

	(void)flag;
	c = va_arg(va, int);
	s = ft_itoabaseint(c, "01234567");
	add_str(s, off);
	return (0);
}

char	letre_mdu(va_list va, t_data_printf *off, t_flag *flag)
{
	unsigned int	c;

	(void)flag;
	c = va_arg(va, unsigned int);
	add_nbr_unsigned(c, off);
	return (0);
}
