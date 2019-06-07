/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strswap.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 14:28:34 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 14:44:13 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_replace_count(const char *str, const char *srch)
{
	size_t	count;

	count = 0;
	while ((str = ft_strstr(str, srch)) != NULL)
	{
		str++;
		count++;
	}
	return (count);
}

char			*ft_strswap(const char *str, const char *srch, const char *repl)
{
	const size_t	rep_size = ft_strlen(repl);
	const size_t	src_size = ft_strlen(srch);
	const char		*previous;
	char			*retval;
	size_t			offset;

	if ((offset = get_replace_count(str, srch)) == 0)
		return (ft_strdup(str));
	if ((retval = (char *)malloc(ft_strlen(str) + 1 + 
					offset * (rep_size - src_size))) == NULL)
		return (retval);
	previous = str;
	offset = 0;
	while ((str = (const char *)ft_strstr(str, srch)) != NULL)
	{
		ft_memcpy(retval + offset, previous, (size_t)(str - previous));
		offset += (size_t)(str - previous);
		ft_memcpy(retval + offset, repl, rep_size);
		offset += rep_size;
		previous = str + src_size;
		str += src_size;
	}
	ft_strcpy(retval + offset, previous);
	return (retval);
}
