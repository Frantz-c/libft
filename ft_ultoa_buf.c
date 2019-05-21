/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ultoa_buf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 13:44:35 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 13:45:58 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_ultoa_buf(char **ptr, unsigned long nb, unsigned int base)
{
	unsigned char	byte;

	while (1)
	{
		byte = nb % base;
		if (byte < 10)
			**ptr = byte + '0';
		else
			**ptr = byte + 'a' - 0xa;
		(*ptr)--;
		if ((nb /= base) == 0)
			break ;
	}
}
