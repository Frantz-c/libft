/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 10:11:45 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:16:13 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*func)(char))
{
	size_t	size;
	size_t	i;
	char	*ret;

	size = ft_strlen(str);
	ret = (char *)malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = func(str[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
