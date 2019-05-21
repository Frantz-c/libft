/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stpncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 16:35:00 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 16:39:13 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stpncpy(char *dst, const char *src, size_t len)
{
	size_t	size;

	size = ft_strlen(src);
	if (size < len)
	{
		ft_memcpy(dst, src, size);
		return (ft_memset(dst + size, '\0', len - size));
	}
	ft_memcpy(dst, src, len);
	return (dst + len);
}
