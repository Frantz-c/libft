/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/10 09:38:26 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/10 09:40:47 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst < src)
		return (ft_memcpy(dst, src, n));
	i = n;
	while (i > 0)
	{
		i--;
		((char *)dst)[i] = ((const char *)src)[i];
	}
	return (dst);
}
