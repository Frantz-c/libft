/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apply_width.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 14:00:50 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:09:44 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	pad_buffer(t_buffer *buffer, char c, size_t times)
{
	uint64_t	k;

	k = (uint8_t)c;
	k *= 0x0101010101010101ull;
	while (times > 7)
	{
		ft_addbuf(buffer, (char *)&k, 8);
		times -= 8;
	}
	ft_addbuf(buffer, (char *)&k, times);
}

static void	adjust_width(t_buffer *buffer, t_format *format)
{
	if (!(format->flags & PF_MINUS))
		pad_buffer(buffer, (format->flags & PF_ZERO) ? '0' : ' ',
				format->width - buffer->next_size);
	ft_addbuf(buffer, buffer->next_data, buffer->next_size);
	if (format->flags & PF_MINUS)
		pad_buffer(buffer, (format->flags & PF_ZERO) ? '0' : ' ',
				format->width - buffer->next_size);
}

void		ft_apply_width(t_buffer *buffer, t_format *format)
{
	buffer->next_size = ft_strlen(buffer->next_data);
	if (buffer->next_size == 0 && format->specifier == 'c')
		buffer->next_size = 1;
	if ((int)buffer->next_size < format->width)
		adjust_width(buffer, format);
	else
		ft_addbuf(buffer, buffer->next_data, buffer->next_size);
	free(buffer->next_data);
}
