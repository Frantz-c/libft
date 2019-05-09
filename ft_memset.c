/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 15:42:28 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/09 16:38:20 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	uint64_t	ptr;
	uint64_t	k;

	ptr = (uint64_t)b;
	k = (uint8_t)c;
	k *= 0x0101010101010101ull;
	while (len > 7)
	{
		*((uint64_t *)ptr) = k;
		ptr += 8;
		len -= 8;
	}
	while (len--)
	{
		*((uint8_t *)ptr) = (uint8_t)k;
		ptr++;
	}
	return (b);
}
