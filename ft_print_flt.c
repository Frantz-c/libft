/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_flt.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:06:30 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:36:34 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_flt(t_buffer *buffer, t_format *format, va_list ap)
{
	long double	d;
	int			size;

	d = (format->flags & PF_LDOUBLE) ? va_arg(ap, long double) :
		(long double)va_arg(ap, double);
	if (!(format->flags & PF_PRECISION))
		format->precision = 6;
	if (ft_inf_nan(buffer, format, d))
		return ;
	ft_flt_add_demi(&d, format->precision);
	size = ft_flt_size(d);
	buffer->next_data = (char *)malloc(size + format->precision + 2);
	ft_flt_get_int(buffer->next_data + size - 1, (d < 0.0) ? -d : d);
	ft_flt_get_dec(buffer->next_data + size, format, (d < 0.0) ? -d : d);
	if (format->flags & PF_ZERO)
		ft_int_zero_padding(buffer, format, d < 0.0);
	if (d < 0.0)
		ft_addbuf_char(buffer, '-');
	else if (format->flags & PF_PLUS)
		ft_addbuf_char(buffer, '+');
	else if (format->flags & PF_SPACE)
		ft_addbuf_char(buffer, ' ');
}
