#include <stdarg.h>
#include <string.h>
#include "libft.h"
#include "printf.h"

char		def_flag_type(va_list va, t_data_printf *off, t_flag *flag)
{
	(void)va;
	(void)off;
	if (*(flag->format) == 'l')
		if (!((flag->flagtype) & FLAG_LONG))
			(flag->flagtype) = FLAG_LONG;
		else
			(flag->flagtype) = FLAG_LONGLONG;
	else if (*(flag->format) == 'h')
		if (!((flag->flagtype) & FLAG_SHORT))
			(flag->flagtype) = FLAG_SHORT;
		else
			(flag->flagtype) = FLAG_CHAR;
	else if (*(flag->format) == 'j')
		(flag->flagtype) = FLAG_MAX;
	else if (*(flag->format) == 'z')
		(flag->flagtype) = FLAG_SIZE_T;
	else
		ft_erreur("imposible\n");
	++(flag->format);
	return (1);
}

char		def_flag(va_list va, t_data_printf *off, t_flag *flag)
{
	(void)va;
	(void)off;
	if (*(flag->format) == '#')
		(flag->flagother) |= FLAG_DIESE;
	else if (*(flag->format) == '-')
		(flag->flagother) |= FLAG_MOIN;
	else if (*(flag->format) == '+')
		(flag->flagother) |= FLAG_PLUS;
	else if (*(flag->format) == ' ')
		(flag->flagother) |= FLAG_SPACE;
	else if (*(flag->format) == '0')
		(flag->flagother) |= FLAG_ZERO;
	else if (ft_isdigit(*(flag->format)))
		(flag->flagother) |= FLAG_ZERO;
	else
		ft_erreur("imposibl\n");
	++(flag->format);
	return (1);
}

char		def_width(va_list va, t_data_printf *off, t_flag *flag)
{
	int tmp;

	(void)off;
	flag->width = 0;
	flag->width_set = 1;
	if (*(flag->format) == '*')
	{
		++(flag->format);
		tmp = va_arg(va, int);
		if(tmp < 0)
		{
			tmp = -tmp;
			flag->flagother |= FLAG_MOIN;
		}
		flag->width = tmp;
	}else
		while(ft_isdigit(*(flag->format)))
			flag->width = flag->width * 10 + *((flag->format)++) - '0';
	return(1);
}

char		def_precision(va_list va, t_data_printf *off, t_flag *flag)
{
	int prec;

	(void)off;
	flag->precision = 0;
	flag->precision_set = 1;
	++(flag->format);
	if (*(flag->format) == '*')
	{
		++(flag->format);
		if ((prec = va_arg(va, int)) >= 0)
			flag->precision = prec;
	}
	else
		while (ft_isdigit(*(flag->format)))
			flag->precision = flag->precision * 10 + *((flag->format)++) - '0';
	return (1);
}
