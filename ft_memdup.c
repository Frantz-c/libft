/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 14:17:21 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 14:18:20 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, size_t size)
{
	void	*retval;

	retval = malloc(size);
	if (retval == NULL)
		return (retval);
	return (ft_memcpy(retval, s, size));
}
