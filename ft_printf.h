#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_format
{
	const char	*s;
	size_t	len;
	va_list	args;
}	t_format;

int	ft_printf(const char *, ...)

#endif