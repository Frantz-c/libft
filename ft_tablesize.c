/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tablesize.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 14:06:30 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 14:11:07 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_tablesize(void **table)
{
	ssize_t	iterator;

	if (!table)
		return (-1);
	iterator = 0;
	while (table[iterator])
		iterator++;
	return (iterator);
}
