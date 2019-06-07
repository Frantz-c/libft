/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_crep.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:59:54 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 14:02:14 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_crep(char *str, int c, int replace)
{
	if ((str = ft_strchr(str, c)) == NULL)
		return (NULL);
	*str = replace;
	return (str);
}
