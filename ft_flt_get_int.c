/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flt_get_int.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:51:29 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 13:53:13 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_flt_get_int(char *buffer, long double value)
{
	while (1)
	{
		*buffer = (int)ft_fmod(value, 10.0) + '0';
		if ((value /= 10.0) < 1.0)
			break ;
		buffer--;
	}
}
