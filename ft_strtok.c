/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strtok.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/10 14:54:25 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:45:43 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *s, const char *delim)
{
	static char	*olds;

	return (ft_strtok_r(s, delim, &olds));
}
