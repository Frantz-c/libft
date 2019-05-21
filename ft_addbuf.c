/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_addbuf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 14:11:59 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:16:17 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_addbuf(t_buffer *buffer, const void *src, size_t size)
{
	void	*tmpbuf;

	if (buffer->max_size == 0)
	{
		buffer->data = ft_memalloc(BUFF_SIZE);
		buffer->size = 0;
		buffer->max_size = BUFF_SIZE;
	}
	if (buffer->max_size - buffer->size < size)
	{
		while (buffer->max_size - buffer->size < size)
			buffer->max_size *= 2;
		tmpbuf = malloc(buffer->max_size);
		ft_memcpy(tmpbuf, buffer->data, buffer->size);
		free(buffer->data);
		buffer->data = tmpbuf;
	}
	ft_memcpy(buffer->data + buffer->size, src, size);
	buffer->size += size;
}
