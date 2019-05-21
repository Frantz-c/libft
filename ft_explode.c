/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   explode.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/10 10:59:29 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:47:14 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_explode(const char *s, const char *delim)
{
	char	**tab;
	char	*scopy;
	char	*token;
	size_t	size;
	size_t	i;

	scopy = ft_strdup(s);
	if (scopy == NULL)
		return (NULL);
	size = ft_wordcount(scopy, delim);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		return (NULL);
	ft_strcpy(scopy, s);
	tab[size] = 0;
	token = ft_strtok(scopy, delim);
	i = 0;
	while (token)
	{
		tab[i] = ft_strdup(token);
		i++;
		token = ft_strtok(NULL, delim);
	}
	free(scopy);
	return (tab);
}
