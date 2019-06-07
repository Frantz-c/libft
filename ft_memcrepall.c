/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcrepall.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 14:14:29 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 14:16:46 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memcrepall(char *str, int c, int replace, size_t size)
{
	char	*ptr;
	size_t	count;

	count = 0;
	while ((ptr = ft_memchr(str, c, size)) != NULL)
	{
		*(ptr++) = replace;
		size -= (size_t)(ptr - str);
		str = ptr;
		count++;
	}
	return (count);
}
