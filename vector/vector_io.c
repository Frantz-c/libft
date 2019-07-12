/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector_io.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 14:38:24 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 14:40:01 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"

int			vector_insert(t_vector *vec, const void *elem, size_t index)
{
	void	*tmp;

	if (vec->nitems == vec->maxitems)
	{
		vec->maxitems = (vec->maxitems == 0) ? 16 : vec->maxitems * 2;
		tmp = ft_realloc(vec->data, vec->nitems * vec->elemsize,
			vec->maxitems * vec->elemsize);
		if (tmp == NULL)
			return (-1);
		vec->data = tmp;
	}
	if (vec->shift == NOT_POWER_OF_TWO)
	{
		ft_memmove(vector_at_mul(vec, index + 1), vector_at_mul(vec, index),
				(vec->nitems - index) * vec->elemsize);
		ft_memcpy(vector_at_mul(vec, index), elem, vec->elemsize);
	}
	else
	{
		ft_memmove(vector_at_shl(vec, index + 1), vector_at_shl(vec, index),
				(vec->nitems - index) << vec->shift);
		ft_memcpy(vector_at_shl(vec, index), elem, vec->elemsize);
	}
	vec->nitems++;
	return (0);
}

void		vector_delete(t_vector *vec, size_t index)
{
	if (vec->shift == NOT_POWER_OF_TWO)
	{
		ft_memcpy(vector_at_mul(vec, index), vector_at_mul(vec, index + 1),
				(vec->nitems - index));
	}
	else
	{
		ft_memcpy(vector_at_shl(vec, index), vector_at_shl(vec, index + 1),
				(vec->nitems - index));
	}
	vec->nitems--;
}
