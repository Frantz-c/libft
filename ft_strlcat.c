/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 08:19:02 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 08:52:14 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dst, len);
	if (dstlen != len)
	{
		if (srclen >= len - dstlen)
		{
			ft_memcpy(dst + dstlen, src, len - dstlen - 1);
			dst[len - 1] = '\0';
		}
		else
			ft_memcpy(dst + dstlen, src, srclen + 1);
	}
	return (dstlen + srclen);
}
