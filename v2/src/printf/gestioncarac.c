/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestioncarac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 22:48:32 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/18 01:33:15 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void            stk_uni(unsigned int uni, t_data_printf *off)
{
	char        n;

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
