/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 16:00:37 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 16:03:34 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t	size;
	size_t	dstlen;

	size = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (len > size)
		len = size;
	ft_memcpy(dst + dstlen, src, len);
	dst[dstlen + len] = '\0';
	return (dst);
}
