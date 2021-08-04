#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
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

	if (*pd->s == '%')
		c = '%';
	else
		c = va_arg(pd->args, int) % 256;
	pd->len += write(1, &c, 1);
	pd->s++;
	return (1);
}

int	write_string(t_format *pd)
{
	char	*str;

	str = va_arg(pd->args, char *);
	if (str == NULL)
		str = "(null)";
	pd->len += write(1, str, ft_strlen(str));
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
	//printf("%c",*pd->s);
	if (*pd->s == '%'|| *pd->s == 'c')
		return (write_char(pd));
	if (*pd->s == 's')
		return (write_string(pd));
	if (*pd->s == 'd' || *pd->s == 'i')
		return (write_num(pd));
	return (0);
}

// test string ("This is %c", 'a')
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

/*
NULL / Empty string
ft_printf(NULL);
prinft(NULL);
ft_printf("");
printf("");

Single Char
ft_printf("This is %c\n", 'A');
printf("This is %c\n", 'A');
ft_printf("This is %c %c %c %c\n", 'A', 'c', 'D', 'f');
printf("This is %c %c %c %c\n", 'A', 'c', 'D', 'f');
ft_printf("This is %c\n", -65);
printf("This is %c\n", -65);
ft_printf("This is %c\n", 67);
printf("This is %c\n", 67);
ft_printf("This is %c %c %c\n", 'A', "c", 'a');
printf("This is %c %c %c\n", 'A', "c", 'a');
ft_printf("This is %%\n");
printf("This is %%\n");

Numbers d/i


Strings
NULL arg
"" arg

*/
int	main(void)
{
	int	i;

	i = ft_printf("This is %s\n", "");
	printf("%d\n", i);
	i = printf("This is %s\n", "");
	printf("%d\n", i);
}