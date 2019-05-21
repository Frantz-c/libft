/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_int_set_precision.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:29:15 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 15:48:18 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_set_precision(t_buffer *buffer, t_format *format)
{
	int		size;
	char	*tmp;

	format->flags &= (~PF_ZERO);
	if (!format->precision && buffer->next_data[0] == '0')
	{
		buffer->next_data[0] = '\0';
		return ;
	}
	size = ft_strlen(buffer->next_data)
		+ ((format->flags & PF_SHARP) && format->specifier == 'o');
	if (size > format->precision)
		return ;
	tmp = (char *)malloc(format->precision + 1);
	ft_memset(tmp, '0', format->precision - size);
	ft_memcpy(tmp + format->precision - size, buffer->next_data,
		ft_strlen(buffer->next_data) + 1);
	free(buffer->next_data);
	buffer->next_data = tmp;
}
