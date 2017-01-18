/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:44:59 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/18 01:30:17 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "printf.h"

int				sizeofbit(int nb)
{
	int		i;

	i = 1;
	while (nb >>= 1)
		++i;
	return (i);
}

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

void			uni_aff(int *uni, t_data_printf *off)
{
	--uni;
	while (*(++uni))
		stk_uni(*uni, off);
}
