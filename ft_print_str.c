/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_str.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:42:06 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 12:45:02 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_str(t_buffer *buffer, t_format *format, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = (char *)"(null)";
	if (format->flags & PF_PRECISION)
		buffer->next_data = ft_strndup(str, format->precision);
	else
		buffer->next_data = ft_strdup(str);
}
