/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtok_r.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 10:45:45 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:45:55 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok_r(char *s, const char *delim, char **oldptr)
{
	char	*end;

	if (!s)
		s = *oldptr;
	if (!*s)
	{
		*oldptr = s;
		return (NULL);
	}
	s += ft_strspn(s, delim);
	if (!*s)
	{
		*oldptr = s;
		return (NULL);
	}
	end = s + ft_strcspn(s, delim);
	if (!*end)
	{
		*oldptr = end;
		return (s);
	}
	*end = '\0';
	*oldptr = end + 1;
	return (s);
}
