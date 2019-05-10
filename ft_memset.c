/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 15:42:28 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/10 12:34:46 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	memset_big(void *b, int c, size_t len)
{
	uint64_t	k;

	k = (uint8_t)c;
	k *= 0x0101010101010101;
	while (len > 63)
	{
		((uint64_t *)b)[0] = k;
		((uint64_t *)b)[1] = k;
		((uint64_t *)b)[2] = k;
		((uint64_t *)b)[3] = k;
		((uint64_t *)b)[4] = k;
		((uint64_t *)b)[5] = k;
		((uint64_t *)b)[6] = k;
		((uint64_t *)b)[7] = k;
		b += 64;
		len -= 64;
	}
}

static void	memset_medium(void *b, int c, size_t len)
{
	uint64_t	k;

	k = (uint8_t)c;
	k *= 0x0101010101010101;
	while (len > 7)
	{
		*((uint64_t *)b) = k;
		b += 8;
		len -= 8;
	}
}

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*bsave;

	bsave = b;
	if (len >= 64)
	{
		memset_big(b, c, len);
		b += (len & (~63ull));
		len &= 63ull;
	}
	if (len >= 8)
	{
		memset_medium(b, c, len);
		b += (len & (~7ull));
		len &= 7ull;
	}
	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (bsave);
}
