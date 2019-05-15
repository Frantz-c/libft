/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 09:05:12 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 09:10:54 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
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
		if (ft_memcmp(next_ptr, little, llen) == 0)
			break ;
		next_ptr = ft_strchr(next_ptr + 1, lchar);
	}
	return (next_ptr);
}
