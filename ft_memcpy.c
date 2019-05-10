/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/10 09:01:59 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/10 09:54:14 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ptrsave;

	ptrsave = dst;
	while (n > 7)
	{
		*((int64_t *)dst) = *((const int64_t *)src);
		dst += 8;
		src += 8;
		n -= 8;
	}
	while (n--)
	{
		*((int8_t *)dst) = *((const int8_t *)src);
		dst++;
		src++;
	}
	return (ptrsave);
}
