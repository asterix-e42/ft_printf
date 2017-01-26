#include "printf.h"

char	letre_mdu(va_list va, t_data_printf *off, t_flag *flag)
{
	unsigned int	c;

	(void)flag;
	c = va_arg(va, unsigned int);
	add_nbr_unsigned(c, off);
	return (0);
}
