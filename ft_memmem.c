/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmem.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 16:54:26 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 16:57:39 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmem(const void *big, size_t blen, const char *little,
			size_t llen)
{
	void	*next_ptr;
	char	lchar;

	lchar = *((const char *)little);
	next_ptr = ft_memchr(big, lchar, blen - llen + 1);
	while (next_ptr != NULL)
	{
		if (ft_memcmp(next_ptr, little, llen) == 0)
			break ;
		next_ptr = ft_memchr(next_ptr + 1, lchar, blen - llen + big - next_ptr);
	}
	return (next_ptr);
}
