/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 11:49:37 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 11:54:37 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*func)(t_list *))
{
	t_list	*ret;

	ret = NULL;
	while (lst)
	{
		ft_lstpush(&ret, func(lst));
		lst = lst->next;
	}
	return (ret);
}
