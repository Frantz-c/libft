/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_npt.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:45:25 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 12:48:28 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_npt(t_buffer *buffer, t_format *format, va_list ap)
{
	void	*nptr;

	nptr = va_arg(ap, void *);
	if (format->flags & PF_LONG)
		*((long int *)nptr) = (long int)buffer->size;
	else if (format->flags & PF_CHAR)
		*((char *)nptr) = (char)buffer->size;
	else if (format->flags & PF_SHORT)
		*((short *)nptr) = (short)buffer->size;
	else
		*((int *)nptr) = (int)buffer->size;
	buffer->next_data = (char *)malloc(1);
	buffer->next_data[0] = '\0';
}
