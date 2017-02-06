/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:50:23 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/18 01:32:33 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "libft.h"
#include <stdarg.h>
#include <stdint.h>

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

#define MAX(nb1, nb2) (nb1 < nb2)?nb2:nb1

typedef struct	s_data_printf
{
	int			size;
	char		*txt;
	int			tmp;
}		t_data_printf;

typedef struct	s_flag
{
	char		*format;
	char		flagtype;
	char		flagother;
	char		precision_set;
	char		width_set;
	unsigned int			precision;
	unsigned int			width;
}		t_flag;

char			def_flag_type(va_list va, t_data_printf *off, t_flag *flag);
char			def_flag(va_list va, t_data_printf *off, t_flag *flag);
char			def_width(va_list va, t_data_printf *off, t_flag *flag);
char			def_precision(va_list va, t_data_printf *off, t_flag *flag);
int				sizeofbit(int);
void			add_chr(char c, t_data_printf *off);
void			add_n_chr(unsigned int len, char c, t_data_printf *off);
void			add_str(char *c, t_data_printf *off);
void			stk_uni(unsigned int uni, t_data_printf *off);
int				ft_printf(const char *format, ...);
void			print(t_data_printf *off, int fd);
void			add_nbr(intmax_t nb, t_data_printf *off);
void			add_nbr_unsigned(unsigned int nb, t_data_printf *off);
void			uni_aff(int *uni, t_data_printf *off);
void			add_itoabase(long int b, char *c, t_data_printf *off);
int				atoistr(char **s);
t_data_printf	*new_data(void);
t_flag			*new_flag(char *);

void			init(char(* tabprint[127])(va_list, t_data_printf *, t_flag *));
char			symbol_a(va_list va, t_data_printf *off, t_flag *);
char			letre_c(va_list va, t_data_printf *off, t_flag *);
char			letre_s(va_list va, t_data_printf *off, t_flag *);
char			letre_id(va_list va, t_data_printf *off, t_flag *);
char			letre_x(va_list va, t_data_printf *off, t_flag *);
char			letre_p(va_list va, t_data_printf *off, t_flag *);
char			letre_mx(va_list va, t_data_printf *off, t_flag *);
char			letre_moo(va_list va, t_data_printf *off, t_flag *);
char			letre_mdu(va_list va, t_data_printf *off, t_flag *);

#endif
