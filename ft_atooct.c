/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atooct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:52:49 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 13:54:43 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atooct(const char *str)
{
	unsigned int	result;

	while (ft_isspace(*str))
		str++;
	result = 0;
	if (*str != '0')
		return (result);
	str++;
	while (*str >= '0' && *str <= '7')
	{
		result <<= 3;
		result += *str - '0';
		str++;
	}
	return (result);
}
