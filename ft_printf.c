#include "ft_printf.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
		i++;
	return (i);
}

void	ft_put_str(const char *s)
{
	write(1, s, ft_strlen(s));
}

int	write_char(t_format *pd)
{
	char	c;

	c = va_arg(pd->args, int) % 256;
	pd->len += write(1, &c, 1);
	pd->s++;
	return (1);
}

/*
*	parser: parses format string into diff specifying fns for formatting
*	params: 1. string from original printf str 2. arg from printf arg
*	return: len of parsed string, -1 if error
*/
int	format_parser(t_format *pd)
{
	if (*pd->s == 'c')
		write_char(pd);
	return (1);
}

// test string ("This is %c", 'a')
int	ft_printf(const char *s, ...)
{
	t_format	pd;

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

int	main(void)
{
	int	i;

	i = ft_printf("Hello %c %c\n", 'A','c');
	printf("%d\n", i);
	i = printf("Hello %c %c\n", 'A','c');
	printf("%d\n", i);
}