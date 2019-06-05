/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 11:28:41 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 08:16:29 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fill_tmp(char **line, char **excess_buf, char *newline_pointer)
{
	char	*str;

	if (newline_pointer)
	{
		*line = ft_strndup(*excess_buf, (size_t)(newline_pointer - *excess_buf));
		str = ft_strdup(newline_pointer + 1);
	}
	else
	{
		*line = ft_strdup(*excess_buf);
		str = NULL;
	}
	free(*excess_buf);
	*excess_buf = str;
	if (line == NULL || (newline_pointer != NULL && str == NULL))
		return (-1);
	return ((**line) != '\0' || (*excess_buf) != NULL);
}

int			ft_get_next_line(int fd, char **line)
{
	static char	*excess_buffer;
	ssize_t		read_size;
	char		*str_tmp;
	char		buffer[BUFF_SIZE + 1];

	if (!excess_buffer)
		excess_buffer = (char *)ft_memalloc(BUFF_SIZE + 1);
	if (read(fd, NULL, 0) == -1 || !line || !excess_buffer)
		return (-1);
	str_tmp = ft_strchr(excess_buffer, '\n');
	while ((read_size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_size] = '\0';
		str_tmp = ft_strjoin(excess_buffer, buffer);
		if (!str_tmp)
			return (-1);
		free(excess_buffer);
		excess_buffer = str_tmp;
		if ((str_tmp = ft_strchr(excess_buffer, '\n')) != NULL)
			break ;
	}
	return (ft_fill_tmp(line, &excess_buffer, str_tmp));
}
