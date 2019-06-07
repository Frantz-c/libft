/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_crrep.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 14:02:48 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 14:03:27 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_crrep(char *str, int c, int replace)
{
	if ((str = ft_strrchr(str, c)) == NULL)
		return (NULL);
	*str = replace;
	return (str);
}
