/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_pop_integers.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 09:51:44 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:54:50 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "barray.h"

int		array_pop_char(t_barray *array, char *c)
{
	if (array->usize < sizeof(char))
		return (0);
	*c = *(char *)(array->data + array->usize - sizeof(char));
	array->usize -= sizeof(char);
	return (1);
}

int		array_pop_short(t_barray *array, short *s)
{
	if (array->usize < sizeof(short))
		return (0);
	*s = *(short *)(array->data + array->usize - sizeof(short));
	array->usize -= sizeof(short);
	return (1);
}

int		array_pop_int(t_barray *array, int *i)
{
	if (array->usize < sizeof(int))
		return (0);
	*i = *(int *)(array->data + array->usize - sizeof(int));
	array->usize -= sizeof(int);
	return (1);
}

int		array_pop_long(t_barray *array, long *l)
{
	if (array->usize < sizeof(long))
		return (0);
	*l = *(long *)(array->data + array->usize - sizeof(long));
	array->usize -= sizeof(long);
	return (1);
}
