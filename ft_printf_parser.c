#include "ft_printf.h"

/*	write_address:	prints character
*	params:			takes in t_format, uses va_arg in struct to get int from arg		
*	return:			if success, return 1
*					if error, return 0
*/
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

/*	write_address:	prints string
*	params:			takes in t_format, uses va_arg in struct to get string from arg
*	return:			if success, return 1
*					if error, return 0
*/
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

/*	write_address:	prints number in decimals representation
*	params:			takes in t_format, uses va_arg in struct to get int from arg
*	return:			if success, return 1
*					if error, return 0
*/
int	write_num(t_format *pd)
{
	long	i;

	if (*pd->s == 'u')
		i = va_arg(pd->args, unsigned int);
	if (*pd->s == 'i' || *pd->s == 'd')
		i = va_arg(pd->args, int);
	if (i < 0)
	{
		pd->len += write(1, "-", 1);
		i *= -1;
	}
	pd->len += put_base(i, 10, DEC_BASE);
	pd->s++;
	return (1);
}

/*	write_address:	prints number in hex representation
*	params:	takes in t_format, 
*			uses va_arg in struct to get unsigned int for hex conversion
*	return:			if success, return 1
*					if error, return 0
*/
int	write_hex(t_format *pd)
{
	unsigned long	i;

	i = va_arg(pd->args, unsigned int);
	if (*pd->s == 'x')
		pd->len += put_base(i, 16, HEX_BASE_LOWER);
	else
		pd->len += put_base(i, 16, HEX_BASE_UPPER);
	pd->s++;
	return (1);
}

/*	write_address:	prints pointer address
*	params:	takes in t_format, 
*			uses va_arg in struct to get pointer address from arg
*	return:	if success, return 1
*					if error, return 0
*/
int	write_address(t_format *pd)
{
	pd->len += write(1, "0x", 2);
	pd->len += put_base(va_arg(pd->args, unsigned long), 16, HEX_BASE_LOWER);
	pd->s++;
	return (1);
}
