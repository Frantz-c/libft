/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 14:22:25 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 14:42:51 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *oldptr, size_t old_size, size_t new_size)
{
	void	*newptr;

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (newptr);
	ft_memcpy(newptr, oldptr, (old_size < new_size) ? old_size : new_size);
	free(oldptr);
	return (newptr);
}
