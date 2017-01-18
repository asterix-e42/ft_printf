/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:28:06 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/17 21:51:07 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdlib.h>

t_data_printf	*new_data(void)
{
	t_data_printf	*ret;

	if (!(ret = (t_data_printf *)malloc(sizeof(t_data_printf))))
		ft_erreur("malloc");
	if (!(ret->txt = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		ft_erreur("malloc");
	ret->size = 0;
	ret->tmp = 0;
	return (ret);
}

t_flag			*new_flag(char *format)
{
	t_flag			*ret;

	if (!(ret = (t_flag *)malloc(sizeof(t_flag))))
		ft_erreur("malloc");
	ret->format = format;
	ret->flagtype = 0;
	ret->flagother = 0;
	ret->precision1 = 0;
	ret->precision2 = 0;
	ret->precision3 = 0;
	return (ret);
}
