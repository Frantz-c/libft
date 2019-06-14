/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_push_data.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 09:58:07 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 10:03:01 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "barray.h"

int		array_push_data(t_barray *array, const char *b, size_t size)
{
	if (array->usize + size > array->msize)
		if (!array_realloc(array, array->usize + size))
			return (0);
	ft_memcpy(array->data + array->usize, b, size);
	array->usize += size;
	return (1);
}

int		array_insert(t_barray *array, const char *b, size_t index, size_t size)
{
	if (array->usize + size > array->msize)
		if (!array_realloc(array, array->usize + size))
			return (0);
	ft_memmove(array->data + index + size, array->data + index,
			array->usize - index);
	ft_memcpy(array->data + index, b, size);
	return (1);
}
