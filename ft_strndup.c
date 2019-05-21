/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 10:27:00 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:30:42 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*ret;
	size_t	size;

	size = ft_strnlen(str, n);
	ret = (char *)malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, str, size);
	ret[size] = '\0';
	return (ret);
}
