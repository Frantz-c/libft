/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_realloc.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 09:32:41 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:37:39 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "barray.h"

int		array_realloc(t_barray *array, size_t new_size)
{
	char	*new_data;

	new_data = (char *)malloc(new_size);
	if (new_data == NULL)
		return (0);
	if (new_size < array->usize)
	{
		ft_memcpy(new_data, array->data, new_size);
		array->usize = new_size;
	}
	else
		ft_memcpy(new_data, array->data, array->usize);
	if (array->data != NULL)
		free(array->data);
	array->data = new_data;
	array->msize = new_size;
	array->align = ft_align(array->data);
	return (1);
}
