/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 10:16:27 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:19:30 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*ret;

	size = (unsigned int)ft_strlen(str);
	ret = (char *)malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = func(i, str[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
