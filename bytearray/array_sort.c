/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_sort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 10:54:24 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 10:55:30 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "barray.h"

void	array_sort(t_barray *array, size_t elemsize, int (*cmp)(void *, void *))
{
	ft_sort(array->data, elemsize, array->usize / elemsize, cmp);
}
