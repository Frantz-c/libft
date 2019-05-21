/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 10:52:21 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 10:58:08 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int val)
{
	static char		buffer[13];
	int				i;
	unsigned int	uval;

	if (val == -2147483648)
		return (ft_strdup("-2147483648"));
	uval = (val < 0) ? -val : val;
	buffer[12] = '\0';
	i = 11;
	while (1)
	{
		buffer[i] = uval % 10 + '0';
		uval /= 10;
		if (uval == 0)
			break ;
		i--;
	}
	if (val < 0)
		buffer[--i] = '-';
	return (ft_strdup(buffer + i));
}
