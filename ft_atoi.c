/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 16:06:21 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 13:57:23 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
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
	if (result > 2147483648 || result < -2147483648)
		return (sign ? 0 : -1);
	return (sign ? -result : result);
}
