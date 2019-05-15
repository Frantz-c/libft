/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 16:06:21 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 16:11:30 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		sign;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
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
