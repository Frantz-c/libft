/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 14:44:41 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 14:52:47 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	size;

	size = ft_strlen(src);
	if (size < n)
	{
		ft_memcpy(dst, src, size);
		ft_bzero(dst + size, n - size);
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
