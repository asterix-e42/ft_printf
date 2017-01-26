#include "printf.h"

char	letre_p(va_list va, t_data_printf *off, t_flag *flag)
{
	long int		c;
	char			*s;

	(void)flag;
	c = va_arg(va, long int);
	add_str("0x", off);
	s = ft_itoabase(c, "0123456789abcdef");
	add_str(s, off);
	return (0);
}
