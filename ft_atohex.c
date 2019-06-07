/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atohex.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/07 13:40:02 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/07 13:47:04 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atohex(const char *str)
{
	unsigned int	result;

	while (ft_isspace(*str))
		str++;
	result = 0;
	if (str[0] != '0' && str[1] != 'x')
		return (result);
	str += 2;
	while (1)
	{
		if (*str >= '0' && *str <= '9')
			result = (result << 4) + *str - '0';
		else if (*str >= 'A' && *str <= 'F')
			result = (result << 4) + *str + 0xA - 'A';
		else if (*str >= 'a' && *str <= 'f')
			result = (result << 4) + *str + 0xA - 'a';
		else
			break ;
		str++;
	}
	return (result);
}
