/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 10:34:51 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:39:08 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
		start++;
	if (str[start] == '\0')
		return (ft_memalloc(1));
	if ((end = ft_strlen(str)) == 0)
		return (ft_memalloc(1));
	end -= 1;
	while (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')
		end--;
	return (ft_strsub(str, start, end - start + 1));
}
