/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_hex.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:53:34 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 12:58:14 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(t_buffer *buffer, t_format *format, va_list ap)
{
	unsigned long	value;

	if (format->flags & PF_LONG)
		value = va_arg(ap, unsigned long);
	else
	{
		value = va_arg(ap, unsigned int);
		if (format->flags & PF_CHAR)
			value = (unsigned char)value;
		else if (format->flags & PF_SHORT)
			value = (unsigned short)value;
	}
	ft_get_uint(buffer, value, 16);
	if (format->flags & PF_PRECISION)
		ft_int_set_precision(buffer, format);
	if (format->flags & PF_ZERO)
		ft_int_zero_padding(buffer, format, 0);
	if (format->flags & PF_SHARP)
		ft_int_sharp(buffer, format);
	if (format->specifier == 'X')
		ft_uppercase(buffer->next_data);
}
