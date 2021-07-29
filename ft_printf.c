#include "ft_printf.h"
#include <unistd.h>

static int	convert_pct(t_printf *st)
{
	if (*st->format == '%')
		return (st->len += ft_putstr("%"));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_printf	st;

	st = (t_printf){.format = format, .len = 0};
	va_start(st.ap, format);
	while (*st.format)
	{
		if (*st.format == '%')
		{
			++st.format;
			if (!(convert_c(&st) || convert_s(&st) || convert_pct(&st)
					|| convert_diu(&st) || convert_p(&st) || convert_xX(&st)))
				return (-1);
			++st.format;
		}
		while (*st.format && *st.format != '%')
			st.len += write(1, st.format++, 1);
	}
	va_end(st.ap);
	return (st.len);
}
