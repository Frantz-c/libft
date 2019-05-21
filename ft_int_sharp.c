/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_int_sharp.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:38:46 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:22:01 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_sharp(t_buffer *buffer, t_format *format)
{
	char	*tmp;

	if (buffer->next_data[0] == '\0' && format->specifier == 'o')
	{
		free(buffer->next_data);
		buffer->next_data = ft_strdup("0");
		return ;
	}
	if ((buffer->next_data[0] == '\0' ||
		(buffer->next_data[0] == '0' && buffer->next_data[1] == '\0')) &&
		format->specifier != 'p')
		return ;
	tmp = (char *)malloc(ft_strlen(buffer->next_data) +
		(format->specifier != 'o') + 2);
	tmp[0] = '0';
	if (format->specifier == 'o')
		ft_strcpy(tmp + 1, buffer->next_data);
	else
	{
		tmp[1] = 'x';
		ft_strcpy(tmp + 2, buffer->next_data);
	}
	free(buffer->next_data);
	buffer->next_data = tmp;
}
