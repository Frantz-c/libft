/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 20:29:52 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 20:32:57 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

extern void		print_array(t_array *a)
{
	int i;

	i = 0;
	while (i < a->length)
	{
		write(1, a->array[i], ft_strlen(a->array[i]));
		i++;
	}
}

extern void		free_array(t_array *a)
{
	int i;

	i = 0;
	while (i < a->length)
	{
		if (a->array[i])
			free(a->array[i]);
		i++;
	}
	free(a->array);
	free(a);
}
