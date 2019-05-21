/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_int_zero_padding.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:33:11 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 13:38:33 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_zero_padding(t_buffer *buffer, t_format *format, _Bool sign)
{
	int		size;
	int		padsize;
	char	*tmp;

	size = ft_strlen(buffer->next_data);
	padsize = format->width - size;
	format->flags &= (~PF_ZERO);
	if ((format->flags & PF_SHARP) && ft_strchr("oxX", format->specifier))
		padsize -= (format->specifier == 'o') ? 1 : 2;
	padsize -= ((format->flags & (PF_PLUS | PF_SPACE)) || sign);
	if (padsize <= 0)
		return ;
	tmp = (char *)malloc(padsize + size + 1);
	ft_memset(tmp, '0', padsize);
	ft_memcpy(tmp + padsize, buffer->next_data, size + 1);
	free(buffer->next_data);
	buffer->next_data = tmp;
}
