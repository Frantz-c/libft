/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_uint.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:27:23 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:21:14 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_uint(t_buffer *buffer, unsigned long value, unsigned int base)
{
	char	*ptr;

	buffer->next_data = (char *)malloc(24);
	buffer->next_data[23] = '\0';
	ptr = buffer->next_data + 22;
	ft_ultoa_buf(&ptr, value, base);
	ft_memmove(buffer->next_data, ptr + 1, ft_strlen(ptr + 1) + 1);
}
