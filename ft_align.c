/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_align.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 09:20:55 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:23:20 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_align(void *data)
{
	if (((intptr_t)data & 63) == 0)
		return (64);
	if (((intptr_t)data & 31) == 0)
		return (32);
	if (((intptr_t)data & 15) == 0)
		return (16);
	if (((intptr_t)data & 7) == 0)
		return (8);
	if (((intptr_t)data & 3) == 0)
		return (4);
	if (((intptr_t)data & 1) == 0)
		return (2);
	return (1);
}
