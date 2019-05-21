/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchrnul.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 14:49:44 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:49:58 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrnul(const char *str, int c)
{
	if ((char)c == 0)
		return (NULL);
	return (ft_strchr(str, c));
}
