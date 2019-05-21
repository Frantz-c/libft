/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flt_get_dec.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:52:41 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:20:35 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_flt_get_dec(char *buffer, t_format *format, long double value)
{
	if (format->precision > 0 || (format->flags & PF_SHARP))
		*buffer = '.';
	else
	{
		*buffer = '\0';
		return ;
	}
	value = ft_fmod(value, 1.0);
	buffer++;
	while (format->precision--)
	{
		*buffer = (int)(value * 10.0) + '0';
		buffer++;
		value = ft_fmod(value * 10.0, 1.0);
	}
	*buffer = '\0';
	format->flags &= (~PF_PRECISION);
}
