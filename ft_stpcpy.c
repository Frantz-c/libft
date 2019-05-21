/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stpcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 16:33:50 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 16:34:47 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stpcpy(char *dst, const char *src)
{
	return (ft_memccpy(dst, src, '\0', UINT64_MAX) - 1);
}