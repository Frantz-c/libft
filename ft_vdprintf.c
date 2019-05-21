/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vdprintf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:10:19 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 12:16:48 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_buffer	buffer;
	int			retval;
	const char	*tmp;

	ft_bzero(&buffer, sizeof(t_buffer));
	while (*fmt)
	{
		if ((tmp = ft_strchr(fmt, '%')) != NULL)
		{
			ft_addbuf(&buffer, (void *)fmt, (size_t)(tmp - fmt));
			fmt = ft_printconv(&buffer, tmp, ap);
		}
		else
		{
			ft_addbuf(&buffer, fmt, ft_strlen(fmt));
			break ;
		}
	}
	retval = write(fd, buffer.data, buffer.size);
	free(buffer.data);
	return (retval);
}
