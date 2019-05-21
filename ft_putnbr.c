/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 11:05:20 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 11:09:24 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int val)
{
	static char		buffer[13];
	int				i;
	unsigned int	uval;

	if (val == -2147483648)
	{
		write(1, "-2147483648", 12);
		return ;
	}
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
	write(1, buffer + i, 12 - i);
}
