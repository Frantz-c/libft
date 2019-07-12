/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector_at.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 14:24:38 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 14:27:02 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vector.h"

extern inline void		*vector_at_mul(t_vector *vec, size_t index)
{
	return (vec->data + (index * vec->elemsize));
}

extern inline void		*vector_at_shl(t_vector *vec, size_t index)
{
	return (vec->data + (index << vec->shift));
}

extern void				*vector_at(t_vector *vec, size_t index)
{
	if (vec->shift == NOT_POWER_OF_TWO)
	{
		return (vector_at_mul(vec, index));
	}
	else
	{
		return (vector_at_shl(vec, index));
	}
}
