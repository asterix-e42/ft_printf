#include "printf.h"

char	letre_s(va_list va, t_data_printf *off, t_flag *flag)
{
	char	*c;

	(void)flag;
	c = va_arg(va, char *);
	add_str(c, off);
	return (0);
}
