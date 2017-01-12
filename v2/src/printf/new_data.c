
#include "ft_printf.h"

t_data_printf *new_data(void)
{
	t_data_printf ret;

	ret->size = 0;
	ret->txt = "";
	ret->tmp = 0;
	return(ret);
}
