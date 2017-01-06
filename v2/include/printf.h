/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:50:23 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/06 07:52:23 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "libft.h"

# define BUFF_SIZE 1024
# define FLAG_DIESE 1
# define FLAG_ZERO 2
# define FLAG_MOIN 4
# define FLAG_PLUS 8
# define FLAG_SPACE 16

# define FLAG_LONGLONG 1
# define FLAG_LONG 2
# define FLAG_CHAR 4
# define FLAG_SHORT 8
# define FLAG_MAX 16
# define FLAG_SIZE_T 32

union u_size_of_type
{
	char c;
};

void			add_chr(char c, t_list *off);
void			add_str(char *c, t_list *off);
void			stk_uni(unsigned int uni, t_list *off);
int				ft_printf(const char *format, ...);
void			print(t_list *off, int fd);
void			add_nbr(long long int nb, t_list *off);
void			add_nbr_unsigned(unsigned int nb, t_list *off);
void			uni_aff(int *uni, t_list *off);
void			add_itoabase(long int b, char *c, t_list *off);
int				atoistr(char **s);

#endif
