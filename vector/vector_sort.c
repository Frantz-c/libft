/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector_sort.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 14:38:06 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 14:40:07 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"

void		vector_sort(t_vector *vec)
{
	ft_sort(vec->data, vec->nitems, vec->elemsize, vec->compar);
}

ssize_t		vector_search(t_vector *vec, const void *elem)
{
	size_t	left;
	size_t	right;
	size_t	middle;
	int		side;

	if (vec->nitems == 0)
		return (-1);
	left = 0;
	right = vec->nitems - 1;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (vec->shift == NOT_POWER_OF_TWO)
			side = vec->compar(elem, vector_at_mul(vec, middle));
		else
			side = vec->compar(elem, vector_at_shl(vec, middle));
		if (side < 0)
			left = middle + 1;
		else if (side > 0)
			right = middle - 1;
		else
			return ((ssize_t)middle);
	}
	return (-1);
}

size_t		vector_index(t_vector *vec, const void *elem)
{
	size_t	left;
	size_t	right;
	size_t	middle;
	int		side;

	if (vec->nitems == 0)
		return (0);
	left = 0;
	right = vec->nitems - 1;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (vec->shift == NOT_POWER_OF_TWO)
			side = vec->compar(elem, vector_at_mul(vec, middle));
		else
			side = vec->compar(elem, vector_at_shl(vec, middle));
		if (side < 0)
			left = middle + 1;
		else
			right = middle;
	}
	return (left);
}
