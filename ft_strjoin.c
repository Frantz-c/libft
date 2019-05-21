/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 10:32:03 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:33:49 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *left, const char *right)
{
	size_t	left_size;
	size_t	right_size;
	char	*ret;

	left_size = ft_strlen(left);
	right_size = ft_strlen(right);
	ret = (char *)malloc(left_size + right_size + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, left, left_size);
	ft_memcpy(ret + left_size, right, right_size);
	ret[left_size + right_size] = '\0';
	return (ret);
}
