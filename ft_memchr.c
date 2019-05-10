/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/10 09:21:19 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/10 11:26:05 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	*memchr_8(const uint8_t *ptr, uint8_t c)
{
	if (ptr[0] == c)
		return ((void *)(ptr + 0));
	if (ptr[1] == c)
		return ((void *)(ptr + 1));
	if (ptr[2] == c)
		return ((void *)(ptr + 2));
	if (ptr[3] == c)
		return ((void *)(ptr + 3));
	if (ptr[4] == c)
		return ((void *)(ptr + 4));
	if (ptr[5] == c)
		return ((void *)(ptr + 5));
	if (ptr[6] == c)
		return ((void *)(ptr + 6));
	return ((void *)(ptr + 7));
}

void		*ft_memchr(const void *s, int c, size_t n)
{
	uint64_t	k;
	uint64_t	r;

	k = (uint8_t)c;
	k *= 0x0101010101010101ull;
	while (n > 7)
	{
		r = *((const uint64_t *)s) ^ k;
		if ((r - 0x0101010101010101ull) & (~r) & 0x8080808080808080ull)
			return (memchr_8((const uint8_t *)s, (uint8_t)k));
		s += 8;
		n -= 8;
	}
	while (n--)
	{
		if (*((const uint8_t *)s) == (uint8_t)k)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
