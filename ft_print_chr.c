/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_chr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:40:02 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 12:41:53 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_chr(t_buffer *buffer, t_format *format, va_list ap)
{
	buffer->next_data = (char *)malloc(2);
	buffer->next_data[0] = (char)va_arg(ap, int);
	buffer->next_data[1] = '\0';
	(void)format;
}
