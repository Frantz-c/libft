/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_init.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 09:08:30 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:31:52 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "barray.h"

t_barray	*array_init(size_t size)
{
	t_barray	*array;

	array = (t_barray *)malloc(sizeof(t_barray));
	if (array == NULL)
		return (NULL);
	array->data = (char *)malloc(size);
	if (array->data == NULL)
	{
		free(array);
		return (NULL);
	}
	array->usize = 0;
	array->msize = 0;
	array->align = ft_align(array->data);
	return (array);
}

t_barray	*array_init_copy(const char *data, size_t size, size_t buffer_size)
{
	t_barray	*array;

	array = (t_barray *)malloc(sizeof(t_barray));
	if (array == NULL)
		return (NULL);
	array->data = (char *)malloc(buffer_size);
	if (array->data == NULL)
	{
		free(array);
		return (NULL);
	}
	ft_memcpy(array->data, data, size);
	array->usize = size;
	array->msize = buffer_size;
	array->align = ft_align(array->data);
	return (array);
}

t_barray	*array_init_pointer(char *data, size_t size, size_t buffer_size)
{
	t_barray	*array;

	if (data == NULL || size == 0)
		return (array_init(buffer_size));
	array = (t_barray *)malloc(sizeof(t_barray));
	if (array == NULL)
		return (NULL);
	array->data = data;
	array->usize = size;
	array->msize = buffer_size;
	array->align = ft_align(array->data);
	return (array);
}
