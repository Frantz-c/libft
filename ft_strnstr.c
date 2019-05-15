/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 09:10:39 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 09:15:09 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;
	char	*next_ptr;
	char	lchar;

	lchar = *little;
	if (!lchar)
		return ((char *)big);
	llen = ft_strlen(little);
	next_ptr = ft_strchr(big, lchar);
	while (next_ptr != NULL)
	{
		if (big + len - llen < next_ptr)
			return (NULL);
		if (ft_memcmp(next_ptr, little, llen) == 0)
			break ;
		next_ptr = ft_strchr(next_ptr + 1, lchar);
	}
	return (next_ptr);
}
