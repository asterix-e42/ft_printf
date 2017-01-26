/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestionnombre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 22:52:02 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/18 01:32:54 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>

void			itoabase(long int nb, char *b2, t_data_printf *off)
{
	unsigned long int   tmp;
	size_t              size;
	unsigned int        max;

	if (!*b2 && !*(b2 + 1))
		return ;
	size = 1;
	tmp = nb;
	max = ft_strlen(b2);
	while (tmp /= max)
		++size;
	while (--size + 1)
	{
		add_chr(*(b2 + (nb % max)), off);
		nb /= max;
	}
}

int             atoistr(char **s)
{
	int     ret;

	--*s;
	ret = 0;
	while ('0' <= *(++*s) && **s <= '9')
		ret = ret * 10 + (**s - '0');
	--*s;
	return (ret);
}

void            add_nbr_unsigned(unsigned int n, t_data_printf *off)
{
	char    i;

	if (n == 0)
	{
		add_chr('0', off);
		return ;
	}
	i = ft_intlen(n);
	while (--i != -1)
		add_chr('0' + n / ft_power(10, i) % 10, off);
}

void            add_nbr(intmax_t n, t_data_printf *off)
{
	char    i;

	if (n == 0)
	{
		add_chr('0', off);
		return ;
	}
	if ((int)n > 0)
		n = ~n + 1;
	i = ft_intlen(n);
	while (--i != -1)
		add_chr('0' - (int)n / ft_power(10, i) % 10, off);
}
