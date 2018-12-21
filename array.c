/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   array.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 20:29:01 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 20:31:38 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char				**get_copy_array(char **t, int length)
{
	char **new;
	int		i;

	new = (char **)malloc(sizeof(char*) * (length + UPSIZ));
	i = 0;
	while (i < length)
	{
		new[i] = t[i];
		i++;
	}
	free(t);
	return (new);
}

extern t_array			*new_array(void)
{
	t_array *new;

	new = (t_array*)malloc(sizeof(t_array));
	new->a = malloc(sizeof(char*) * UPSIZ);
	new->length = 0;
	new->remainder = UPSIZ;

	return (new);
}

extern inline void		push_array(t_array *a, char *s)
{
	if (a->remainder == 0)
	{
		a->a = get_copy_array(a->a, a->length);
		a->remainder = UPSIZ;
	}

	if (!s)
		a->a[a->length] = NULL;
	else
		a->a[a->length] = ft_strdup(s);
	a->length++;
	a->remainder--;
}


extern inline void		pop_array(t_array *a)
{
	a->length--;
	a->remainder++;
	if (a->a[a->length])
		free(a->a[a->length]);
	if (a->remainder > DOWNSIZ)
	{
		a->a = get_copy_array(a->a, a->length + UPSIZ);
		a->remainder = UPSIZ;
	}
}

extern char				*get_array_n(t_array *a, size_t i)
{
	if (i < a->length)
		return (a->a[i]);
	return (NULL);
}
