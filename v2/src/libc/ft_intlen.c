/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 20:08:03 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/15 03:25:55 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n, char *b)
{
	int		i;
	int		sizeofbase;

	sizeofbase = ft_strlen(b);
	i = 1;
	while ((n /= sizeofbase))
		++i;
	return (i);
}
