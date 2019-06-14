/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_pop_floats.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 09:55:10 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:56:10 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "barray.h"

int		array_pop_float(t_barray *array, float *f)
{
	if (array->usize < sizeof(float))
		return (0);
	*f = *(float *)(array->data + array->usize - sizeof(float));
	array->usize -= sizeof(float);
	return (1);
}

int		array_pop_double(t_barray *array, double *d)
{
	if (array->usize < sizeof(double))
		return (0);
	*d = *(double *)(array->data + array->usize - sizeof(double));
	array->usize -= sizeof(double);
	return (1);
}

int		array_pop_long_double(t_barray *array, long double *ld)
{
	if (array->usize < sizeof(long double))
		return (0);
	*ld = *(long double *)(array->data + array->usize - sizeof(long double));
	array->usize -= sizeof(long double);
	return (1);
}
