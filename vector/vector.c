/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 12:49:01 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 14:38:21 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft.h"

t_vector	*vector_init(size_t elemsize)
{
	t_vector	*vector;

	vector = (t_vector *)malloc(sizeof(t_vector));
	if (vector == NULL || elemsize == 0)
		return (NULL);
	vector->data = NULL;
	vector->elemsize = elemsize;
	vector->nitems = 0;
	vector->maxitems = 0;
	vector->compar = NULL;
	vector->tmp_elem = malloc(elemsize);
	if (vector->tmp_elem == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->shift = NOT_POWER_OF_TWO;
	if (((elemsize - 1) & elemsize) == 0)
	{
		vector->shift = 0;
		while ((elemsize >>= 1) != 0)
			vector->shift++;
	}
	vector->lock = 0;
	return (vector);
}

t_vector	*vector_clone(t_vector *other)
{
	t_vector	*vector;

	if ((vector = (t_vector *)malloc(sizeof(t_vector))) == NULL)
		return (NULL);
	vector->data = malloc(other->elemsize * other->nitems);
	if (vector->data == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->tmp_elem = malloc(other->elemsize);
	if (vector->tmp_elem == NULL)
	{
		free(vector->data);
		free(vector);
		return (NULL);
	}
	ft_memcpy(vector->data, other->data, other->elemsize * other->nitems);
	vector->elemsize = other->elemsize;
	vector->nitems = other->nitems;
	vector->maxitems = other->nitems;
	vector->compar = other->compar;
	vector->shift = other->shift;
	vector->lock = 0;
	return (vector);
}

void		vector_destroy(t_vector *vec)
{
	free(vec->tmp_elem);
	if (vec->data != NULL)
		free(vec->data);
	free(vec);
}
