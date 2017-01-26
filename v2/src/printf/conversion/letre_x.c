#include "printf.h"

char	letre_x(va_list va, t_data_printf *off, t_flag *flag)
{
	int		c;
	char	*s;

	(void)flag;
	c = va_arg(va, int);
	s = ft_itoabaseint(c, "0123456789abcdef");
	add_str(s, off);
	return (0);
}
