#include "ft_printf.h"

/*
*	parser: parses format string into diff specifying fns for formatting
*	params: 1. string from original printf str 2. arg from printf arg
*	return: len of parsed string, -1 if error
*/
static int	format_parser(t_format *pd)
{
	if (*pd->s == '%' || *pd->s == 'c')
		return (write_char(pd));
	if (*pd->s == 's')
		return (write_string(pd));
	if (*pd->s == 'd' || *pd->s == 'i' || *pd->s == 'u')
		return (write_num(pd));
	if (*pd->s == 'x' || *pd->s == 'X')
		return (write_hex(pd));
	if (*pd->s == 'p')
		return (write_address(pd));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	t_format	pd;

	if (!s)
		return (-1);
	pd = (t_format){.s = s, .len = 0};
	va_start(pd.args, s);
	while (*pd.s)
	{
		if (*pd.s == '%')
		{
			pd.s++;
			if (!format_parser(&pd))
				return (-1);
		}
		else
			pd.len += write(1, pd.s++, sizeof(*pd.s));
	}
	va_end(pd.args);
	return (pd.len);
}
