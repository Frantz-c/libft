/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 14:10:09 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 19:12:11 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

#define BUFF_SIZE	25600

static int		set_line(const int fd, char *remainder, char *buf, char **line)
{
	int		readl;
	char	*chrpos;

	while ((readl = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!*line)
			*line = strdup("");
		buf[readl] = '\0';
		if ((chrpos = memchr(buf, '\n', readl)) != NULL)
		{
			ft_memcpy(remainder, chrpos + 1, ft_strlen(chrpos + 1) + 1);
			if (!ft_strnfcat(line, buf, chrpos - buf))
				return (0);
			ft_crep(*line, '\n', '\0');
			return (1);
		}
		if (!ft_strnfcat(line, buf, readl + 1))
			return (0);
	}
	*remainder = '\0';
	return (*line ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static char		remainder[BUFF_SIZE + 1];
	//static char		*next_rem_pos = NULL;
	char			buf[BUFF_SIZE + 1];
	char			*chrpos;

	if (!line)
	{
		*remainder = '\0';
		return (-1);
	}
	if (*line)
		free(*line);
	*line = NULL;
	if (read(fd, buf, 0) < 0)
		return (-1);
	*buf = '\0';
	if (*remainder != '\0')
	{
		if ((chrpos = strchr(remainder, '\n')) != NULL)
		{
			*line = strndup(remainder, chrpos - remainder);
			ft_memmove(remainder, chrpos + 1, ft_strlen(chrpos + 1) + 1);
			return (1);
		}
		*line = strdup(remainder);
	}
	return (set_line(fd, remainder, buf, line));
}
