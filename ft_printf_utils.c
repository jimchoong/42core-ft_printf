#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	put_base(unsigned long num, unsigned int base, const char *base_chars)
{
	int	i;

	i = 1;
	if (num >= base)
		i += put_base(num / base, base, base_chars);
	write(1, &base_chars[num % base], 1);
	return (i);
}
