/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:44:59 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/13 09:21:07 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "printf.h"
#include<stdio.h>
static int		sizeofbit(int nb)
{
	int		i;

	i = 1;
	while (nb >>= 1)
		++i;
	return (i);
}
//fonction non complete
void			add_chr(char c, t_data_printf *off)
{
	(off->txt)[(off->size)] = c;
	++(off->size);
	if (off->size == 1024)
		print(off, 1);
}

void			print(t_data_printf *off, int fd)
{
	write(fd, off->txt, off->size + 1);
	off->tmp = off->size;
	off->size = 0;
}

void			add_str(char *c, t_data_printf *off)
{
	--c;
	while (*(++c))
		add_chr(*c, off);
}

void add_nbr_unsigned(unsigned int n, t_data_printf *off)
{
	char	i;

	if (n == 0)
	{
		add_chr('0', off);
		return ;
	}
	i = ft_intlen(n);
	while (--i != -1)
		add_chr('0' + n / ft_power(10, i) % 10, off);
}

void add_nbr(long long int n, t_data_printf *off)
{
	char	i;

	if (n == 0)
	{
		add_chr('0', off);
		return ;
	}
	if ((int)n < 0)
		add_chr('-', off);
	else
		n = ~n + 1;
	i = ft_intlen(n);
	while (--i != -1)
		add_chr('0' - (int)n / ft_power(10, i) % 10, off);
}

void	add_itoabase(long int nb, char *b2, t_data_printf *off)
{
	unsigned long int	tmp;
//	int					skt;
	size_t				size;
	unsigned int		max;

	if (!b2 && !*b2 && !*(b2 + 1))
		return ;
	size = 1;
	tmp = nb;
//	skt = 0;
	max = ft_strlen(b2);
	while (tmp /= max)
		++size;
	while (--size + 1)
	{
		add_chr(*(b2 + (nb % max)), off);
		nb /= max;
	}
}

int			atoistr(char **s)
{
	int		ret;

	--*s;
	ret = 0;
	while ('0' <= *(++*s) && **s <= '9')
		ret = ret * 10 + (**s - '0');
	--*s;
	return (ret);
}

void			stk_uni(unsigned int uni, t_data_printf *off)
{
	char		n;

	n = sizeofbit(uni);
	if (n > 7)
	{
		if (n > 11)
		{
			if (n > 16)
			{
				add_chr(((uni >> 18) & 7) | 240, off);
				add_chr(((uni >> 12) & 63) | 128, off);
			}
			else
				add_chr(((uni >> 12) & 15) | 224, off);
			add_chr(((uni >> 6) & 63) | 128, off);
		}
		else
			add_chr(((uni >> 6) & 31) | 192, off);
		add_chr((uni & 63) | 128, off);
	}
	else
		add_chr(uni, off);
}

void			uni_aff(int *uni, t_data_printf *off)
{
	--uni;
	while (*(++uni))
		stk_uni(*uni, off);
}
