/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmod.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:50:04 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 13:51:20 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long double	ft_fmod(long double x, long double mod)
{
	long double	lim;

	lim = mod;
	while (x > mod)
		mod *= 2.0;
	while (x >= lim)
	{
		if (mod <= x)
			x -= mod;
		mod /= 2.0;
	}
	return (x);
}
