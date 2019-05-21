/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_inf_nan.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 14:27:30 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:32:59 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

_Bool	ft_inf_nan(t_buffer *buffer, t_format *format, long double v)
{
	union u_ldblcast	test;

	test.d = v;
	if ((test.l[1] & 0x7ffful) == 0x7ffful || v != v)
	{
		if (test.l[0] == 0x8000000000000000ul && ft_islower(format->specifier))
			buffer->next_data = (v < 0) ? ft_strdup("-inf") : ft_strdup("inf");
		else if (test.l[0] == 0x8000000000000000ul)
			buffer->next_data = (v < 0) ? ft_strdup("-INF") : ft_strdup("INF");
		else if (ft_islower(format->specifier))
			buffer->next_data = ft_strdup("nan");
		else
			buffer->next_data = ft_strdup("NAN");
		return (1);
	}
	return (0);
}
