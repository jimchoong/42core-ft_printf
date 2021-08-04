#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define DEC_BASE "0123456789"

typedef struct s_format
{
	const char	*s;
	size_t		len;
	va_list		args;
}	t_format;

int		ft_printf(const char *s, ...);
int		write_char(t_format *pd);
int		write_string(t_format *pd);
int		write_num(t_format *pd);
int		write_hex(t_format *pd);
int		write_address(t_format *pd);
size_t	ft_strlen(const char *s);
int		put_base(unsigned long num, unsigned int base, const char *base_chars);

#endif