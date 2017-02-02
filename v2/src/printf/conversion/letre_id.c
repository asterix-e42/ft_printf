#include "printf.h"
#include "libft.h"
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
	char		*prefix;
	unsigned int	sizeofnb;
	unsigned int	sizeofspace;

	(void)flag;
	c = resize(va, flag);
	sizeofnb = ft_intlen(c, "0123456789");
	if (flag->width_set && !(flag->flagother & FLAG_MOIN) && flag->flagother & FLAG_ZERO)
	{
		if (flag->precision_set)
			flag->precision = MAX(flag->width, flag->precision);
		else
			flag->precision = MAX(flag->width, sizeofnb);
		flag->precision_set = 1;
		flag->width_set = 0;
	}
	sizeofspace = sizeofnb;
	if (flag->precision_set && flag->precision > sizeofnb)
		sizeofspace = flag->precision;
	prefix = "";
	if (c < 0 || (flag->flagother) & FLAG_PLUS || (flag->flagother) & FLAG_SPACE)
	{
		if (c < 0)
		{
			c = ~c + 1;
			prefix = "-";
		}
		else if ((flag->flagother) & FLAG_PLUS)
			prefix = "+";
		else if ((flag->flagother) & FLAG_SPACE)
			prefix = " ";
		sizeofspace += ft_strlen(prefix);
	}
	if (flag->width_set && !(flag->flagother & FLAG_MOIN))
		add_n_chr(flag->width - sizeofspace, ' ', off);
	add_str(prefix, off);
	add_itoabase(c, "0123456789", off);
	if (flag->width_set && flag->flagother & FLAG_MOIN)
		add_n_chr(flag->width - sizeofspace, ' ', off);
	return (0);
}
