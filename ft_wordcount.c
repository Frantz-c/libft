/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wordcount.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 10:43:27 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:43:33 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char *s, const char *delim)
{
	size_t	count;
	char	*token;

	token = ft_strtok(s, delim);
	count = 0;
	while (token)
	{
		count++;
		token = ft_strtok(NULL, delim);
	}
	return (count);
}
