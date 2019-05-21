/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flt_add_demi.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:55:44 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:17:34 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_flt_add_demi(long double *value, int precision)
{
	long double	demi;
	long double	div;
	int			i;
	int			pow;

	demi = 0.5;
	i = 0;
	div = 10.0;
	pow = 1;
	while (i < 13)
	{
		if (precision % (pow * 2) == pow)
		{
			demi /= div;
			precision -= pow;
		}
		div *= div;
		i++;
		pow *= 2;
	}
	if (*value < 0.0)
		(*value) -= demi;
	else
		(*value) += demi;
}
