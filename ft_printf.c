#include "ft_printf.h"

/*
*	format_parser: parses format string into diff specifying fns for formatting
*	params: 1. string from original printf str 2. arg from printf arg
*	return: if success, len of printed string, 
*			if error, return -1 
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

/*
*	ft_printf:	variadic fn that prints a string, taking in n number of arg
*	params:		string s, and variable number of arguments
*	return:		if success, number of bytes printed
*				if error, return -1
*/
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
