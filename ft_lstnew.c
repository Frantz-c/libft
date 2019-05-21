/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 11:34:03 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 11:40:35 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *data, size_t size)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	if (data == NULL || size == 0)
	{
		ret->data = NULL;
		ret->size = 0;
	}
	else
	{
		ret->data = malloc(size);
		if (ret->data == 0)
		{
			free(ret);
			return (NULL);
		}
		ft_memcpy(ret->data, data, size);
		ret->size = size;
	}
	ret->next = NULL;
	return (ret);
}
