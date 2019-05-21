/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_addbuf_char.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:46:02 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 13:48:02 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_addbuf_char(t_buffer *buffer, char c)
{
	char	*tmp;
	size_t	size;

	if (buffer->next_data[0] == '\0')
		return ;
	size = ft_strlen(buffer->next_data);
	tmp = (char *)malloc(size + 2);
	tmp[0] = c;
	ft_memcpy(tmp + 1, buffer->next_data, size + 1);
	free(buffer->next_data);
	buffer->next_data = tmp;
}
