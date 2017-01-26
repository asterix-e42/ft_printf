#include "printf.h"

char    letre_c(va_list va, t_data_printf *off, t_flag *flag)
{
	int     c;

	(void)flag;
	c = va_arg(va, int);
	stk_uni(c, off);
	return (0);
}
