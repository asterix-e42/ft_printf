/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:03:41 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/17 22:33:13 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	init2(char(* tabprint[127])(va_list, t_data_printf *, t_flag *))
{
	tabprint['0'] = (*def_flag);
	tabprint['1'] = (*def_flag);
	tabprint['2'] = (*def_flag);
	tabprint['3'] = (*def_flag);
	tabprint['4'] = (*def_flag);
	tabprint['5'] = (*def_flag);
	tabprint['6'] = (*def_flag);
	tabprint['7'] = (*def_flag);
	tabprint['8'] = (*def_flag);
	tabprint['9'] = (*def_flag);
}

void	init(char(* tabprint[127])(va_list, t_data_printf *, t_flag *))
{
	tabprint['%'] = (*symbol_a);
	tabprint['c'] = (*letre_c);
	tabprint['C'] = (*letre_c);
	tabprint['s'] = (*letre_s);
	tabprint['S'] = (*letre_s);
	tabprint['d'] = (*letre_id);
	tabprint['i'] = (*letre_id);
	tabprint['x'] = (*letre_x);
	tabprint['p'] = (*letre_p);
	tabprint['X'] = (*letre_mx);
	tabprint['o'] = (*letre_moo);
	tabprint['O'] = (*letre_moo);
	tabprint['D'] = (*letre_mdu);
	tabprint['u'] = (*letre_mdu);
	tabprint['l'] = (*def_flag_type);
	tabprint['h'] = (*def_flag_type);
	tabprint['j'] = (*def_flag_type);
	tabprint['z'] = (*def_flag_type);
	tabprint['#'] = (*def_flag);
	tabprint['.'] = (*def_flag);
	tabprint['-'] = (*def_flag);
	tabprint['+'] = (*def_flag);
	tabprint[' '] = (*def_flag);
	init2(tabprint);
}
