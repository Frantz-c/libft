/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 08:31:22 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 08:37:11 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t		i;
	uint64_t	k;

	i = 0;
	while ((uint64_t)(s + i) & 7)
	{
		if (s[i] == '\0' || i == maxlen)
			return (i);
		i++;
	}
	while (1)
	{
		k = *((uint64_t *)(s + i));
		if (((k - 0x0101010101010101ull) & (~k) & 0x8080808080808080ull) ||
			(i + 8) > maxlen)
		{
			while (s[i] != '\0' && i < maxlen)
				i++;
			break ;
		}
		i += 8;
	}
	return (i);
}
