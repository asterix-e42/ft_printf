/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:28:06 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/13 09:20:49 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdlib.h>

t_data_printf *new_data(void)
{
	t_data_printf *ret;

	if(!(ret = (t_data_printf *)malloc(sizeof(t_data_printf))))
		ft_erreur("malloc");
	if(!(ret->txt = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		ft_erreur("malloc");
	ret->size = 0;
	ret->tmp = 0;
	return(ret);
}
