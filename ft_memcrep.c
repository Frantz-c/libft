/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcrep.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 14:12:57 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 14:13:53 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memcrep(char *str, int c, int replace, size_t size)
{
	if ((str = ft_memchr(str, c, size)) == NULL)
		return (NULL);
	*str = replace;
	return (str);
}
