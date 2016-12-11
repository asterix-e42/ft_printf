/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:44:59 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/12 00:07:10 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

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
	write(1, off->content + off->content_size, 1);//f->content_size);
}

void			add_str(char *c, t_list *off)
{
	--c;
	while (*(++c))
		add_chr(*c, off);
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
