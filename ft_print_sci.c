/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_sci.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:12:32 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 13:23:47 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	set_scientific(long double *value, int *size, t_format *format)
{
	if (*value == 0.0)
		return ;
	while (*value >= 10.0L || *value <= -10.0L)
	{
		*value /= 10.0L;
		(*size)++;
	}
	while (*value < 1.0L && *value > -1.0L)
	{
		*value *= 10.0L;
		(*size)++;
	}
	ft_flt_add_demi(value, format->precision);
	while (*value >= 10.0L || *value <= -10.0L)
	{
		*value /= 10.0L;
		(*size)++;
	}
}

static void	add_exponent(char *buf, char specifier, int size)
{
	*buf = specifier;
	buf++;
	if (size < 0)
	{
		*buf = '-';
		size = -size;
	}
	else
		*buf = '+';
	buf++;
	if (size >= 1000)
	{
		*buf = (size / 1000) + '0';
		buf++;
	}
	if (size >= 100)
	{
		*buf = (size / 100) % 10 + '0';
		buf++;
	}
	*buf = (size / 10) % 10 + '0';
	buf++;
	*buf = size % 10 + '0';
	buf++;
	*buf = '\0';
}

void		ft_print_sci(t_buffer *buffer, t_format *format, va_list ap)
{
	long double	value;
	int			size;

	size = 0;
	value = (format->flags & PF_LDOUBLE) ? va_arg(ap, long double) :
		(long double)va_arg(ap, double);
	if (!(format->flags & PF_PRECISION))
		format->precision = 6;
	if (ft_inf_nan(buffer, format, value))
		return ;
	set_scientific(&value, &size, format);
	buffer->next_data = (char *)malloc(format->precision + 9);
	ft_flt_get_int(buffer->next_data, (value < 0.0) ? -value : value);
	ft_flt_get_dec(buffer->next_data + 1, format,
		(value < 0.0) ? -value : value);
	add_exponent(buffer->next_data + ft_strlen(buffer->next_data),
		format->specifier, size);
	if (format->flags & PF_ZERO)
		ft_int_zero_padding(buffer, format, value < 0.0);
	if (value < 0.0)
		ft_addbuf_char(buffer, '-');
	else if (format->flags & PF_PLUS)
		ft_addbuf_char(buffer, '+');
	else if (format->flags & PF_SPACE)
		ft_addbuf_char(buffer, ' ');
}
