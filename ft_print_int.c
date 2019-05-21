/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_int.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:58:23 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:39:31 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int(t_buffer *buffer, t_format *format, va_list ap)
{
	long	value;

	if (format->flags & PF_LONG)
		value = va_arg(ap, long);
	else
	{
		value = va_arg(ap, int);
		if (format->flags & PF_CHAR)
			value = (char)value;
		else if (format->flags & PF_SHORT)
			value = (short)value;
	}
	ft_get_uint(buffer, (value < 0) ? -value : value, 10);
	if (format->flags & PF_PRECISION)
		ft_int_set_precision(buffer, format);
	if (format->flags & PF_ZERO)
		ft_int_zero_padding(buffer, format, (value < 0));
	if (value < 0)
		ft_addbuf_char(buffer, '-');
	else if (format->flags & PF_PLUS)
		ft_addbuf_char(buffer, '+');
	else if (format->flags & PF_SPACE)
		ft_addbuf_char(buffer, ' ');
}
