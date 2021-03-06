/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/10 12:59:31 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 15:58:54 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *s)
{
	uint64_t		k;
	const uint64_t	lmagic = 0x0101010101010101ull;
	const uint64_t	hmagic = 0x8080808080808080ull;
	const char		*ptr;

	ptr = s;
	while ((uint64_t)ptr & 7)
	{
		if (*ptr == '\0')
			return (ptr - s);
		ptr++;
	}
	while (1)
	{
		k = *((uint64_t *)ptr);
		if (((k - lmagic) & (~k) & hmagic))
		{
			while (*ptr)
				ptr++;
			break ;
		}
		ptr += 8;
	}
	return (ptr - s);
}
