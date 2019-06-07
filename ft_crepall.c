/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_crepall.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 14:01:12 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 14:02:03 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_crepall(char *str, int c, int replace)
{
	size_t	count;

	count = 0;
	while ((str = ft_strchr(str, c)) != NULL)
	{
		*(str++) = replace;
		count++;
	}
	return (count);
}
