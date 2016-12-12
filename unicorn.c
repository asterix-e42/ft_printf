/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:44:59 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/12 02:24:16 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "printf.h"

static int		sizeofbit(int nb)
{
	int		i;

	i = 1;
	while (nb >>= 1)
		++i;
	return (i);
}
//fonction non complete
void			add_chr(char c, t_list *off)
{
	((char *)off->content)[++(off->content_size)] = c;
	print(off, 1);
}

void			print(t_list *off, int fd)
{
	write(fd, off->content + off->content_size, 1);//f->content_size);
}

void			add_str(char *c, t_list *off)
{
	--c;
	while (*(++c))
		add_chr(*c, off);
}

void add_nbr(int n, t_list *off)
{
	int	i;

	if (n == 0)
	{
		add_chr('0', off);
		return ;
	}
	if (n < 0)
	{
		if (n == -2147483648)
		{
			add_str("-2147483648", off);
			return ;
		}
		add_chr('-', off);
		n = ~n + 1;
	}
	i = ft_intlen(n);
	while (--i != -1)
		add_chr(n / ft_power(10, i) % 10 + '0', off);
}

void			stk_uni(unsigned int uni, t_list *off)
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

void			uni_aff(int *uni, t_list *off)
{
	--uni;
	while (*(++uni))
		stk_uni(*uni, off);
}
