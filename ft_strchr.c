/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 08:53:29 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 09:01:42 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*strchr_8(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (i < 7)
	{
		if (s[i] == c)
			return ((char *)s + i);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + 7);
}

char		*ft_strchr(const char *s, int c)
{
	const uint64_t	k = (uint64_t)((uint8_t)c) * 0x0101010101010101ull;
	uint64_t		r;
	uint64_t		z;

	while ((uint64_t)s & 7)
	{
		if (*s == (char)k)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
	while (1)
	{
		z = *((const uint64_t *)s);
		r = z ^ k;
		if ((r - 0x0101010101010101ull) & (~r) & 0x8080808080808080ull)
			return (strchr_8(s, (char)k));
		if ((z - 0x0101010101010101ull) & (~z) & 0x8080808080808080ull)
			break ;
		s += 8;
	}
	return (NULL);
}
