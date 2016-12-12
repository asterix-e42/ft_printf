/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:50:23 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/12 02:24:27 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# define BUFF_SIZE 1024

void			add_chr(char c, t_list *off);
void			add_str(char *c, t_list *off);
void			stk_uni(unsigned int uni, t_list *off);
int				ft_printf(const char *format, ...);
void			print(t_list *off, int fd);
void			add_nbr(int nb, t_list *off);
void			uni_aff(int *uni, t_list *off);

#endif
