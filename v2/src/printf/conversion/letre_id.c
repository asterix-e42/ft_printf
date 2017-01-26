#include "printf.h"
#include <stdint.h>

static intmax_t	resize(va_list va, t_flag *flag)
{
	intmax_t	nbr;

	nbr = va_arg(va, intmax_t);
	if ((flag->flagtype) == FLAG_CHAR)
		nbr = (char)nbr;
	else if ((flag->flagtype) == FLAG_SHORT)
		nbr = (short int)nbr;
	else if ((flag->flagtype) == FLAG_LONG)
		nbr = (long int)nbr;
	else if ((flag->flagtype) == FLAG_LONGLONG)
		nbr = (long long int)nbr;
	else if ((flag->flagtype) == FLAG_MAX)
		nbr = (intmax_t)nbr;
	else if ((flag->flagtype) == FLAG_SIZE_T)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

char	letre_id(va_list va, t_data_printf *off, t_flag *flag)
{
	intmax_t	c;

	(void)flag;
	c = resize(va, flag);
	if (c < 0 || (flag->flagother) & FLAG_PLUS || (flag->flagother) & FLAG_SPACE)
	{
		if (c < 0)
			add_chr('-', off);
		else if ((flag->flagother) & FLAG_PLUS)
			add_chr('+', off);
		else if ((flag->flagother) & FLAG_SPACE)
			add_chr(' ', off);
	}
	add_nbr(c, off);
	return (0);
}
