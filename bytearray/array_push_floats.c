/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_push_floats.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 09:44:48 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:50:08 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "barray.h"

int		array_push_float(t_barray *array, float f)
{
	if (array->usize + sizeof(float) > array->msize)
		return (0);
	*(float *)(array->data + array->usize) = f;
	array->usize += sizeof(float);
	return (1);
}

int		array_push_double(t_barray *array, double d)
{
	if (array->usize + sizeof(double) > array->msize)
		return (0);
	*(double *)(array->data + array->usize) = d;
	array->usize += sizeof(double);
	return (1);
}

int		array_push_ldouble(t_barray *array, long double ld)
{
	if (array->usize + sizeof(long double) > array->msize)
		return (0);
	*(long double *)(array->data + array->usize) = ld;
	array->usize += sizeof(long double);
	return (1);
}
