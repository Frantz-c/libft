/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstpush.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 11:52:07 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 11:53:11 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *node)
{
	t_list	*last;

	if (!(*alst))
		*alst = node;
	else
	{
		last = *alst;
		while (last->next)
			last = last->next;
		last->next = node;
	}
}
