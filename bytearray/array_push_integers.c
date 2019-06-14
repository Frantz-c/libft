/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array_push_integers.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 09:38:29 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:44:19 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "barray.h"

int		array_push_char(t_barray *array, char c)
{
	if (array->usize + sizeof(char) > array->msize)
		return (0);
	*(char *)(array->data + array->usize) = c;
	array->usize += sizeof(char);
	return (1);
}

int		array_push_short(t_barray *array, short s)
{
	if (array->usize + sizeof(short) > array->msize)
		return (0);
	*(short *)(array->data + array->usize) = s;
	array->usize += sizeof(short);
	return (1);
}

int		array_push_int(t_barray *array, int i)
{
	if (array->usize + sizeof(int) > array->msize)
		return (0);
	*(int *)(array->data + array->usize) = i;
	array->usize += sizeof(int);
	return (1);
}

int		array_push_long(t_barray *array, long l)
{
	if (array->usize + sizeof(long) > array->msize)
		return (0);
	*(long *)(array->data + array->usize) = l;
	array->usize += sizeof(long);
	return (1);
}
