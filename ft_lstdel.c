/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 11:44:37 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 11:45:57 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*func)(void *, size_t))
{
	t_list	*t;

	while (*alst)
	{
		func((*alst)->data, (*alst)->size);
		t = (*alst)->next;
		free(*alst);
		*alst = t;
	}
}
