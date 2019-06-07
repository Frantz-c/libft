/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:56:39 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 13:57:11 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	result;
	long	sign;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-');
	str += (*str == '-' || *str == '+');
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str;
		result -= '0';
		str++;
	}
	return (sign ? -result : result);
}
