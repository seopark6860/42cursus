/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:22:43 by seopark           #+#    #+#             */
/*   Updated: 2021/05/29 15:44:04 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		gnl_strchr(const char *s, int c)
{
	int len;
	int i;

	len = gnl_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_makeline(char *buf, char **line, int i)
{
	char	*temp;
	int		len;

	len = gnl_strlen(buf);
	if (!(*line = (char *)malloc(i + 1)))
		return (0);
	gnl_strlcpy(*line, buf, i + 1);
	if (!(temp = (char *)malloc(len - (i + 1) + 1)))
		return (0);
	gnl_strlcpy(temp, buf + i + 1, len - (i + 1) + 1);
	free(buf);
	return (temp);
}

int		check_newline(char **buf, char **line)
{
	int i;

	if ((i = gnl_strchr(*buf, '\n')) != -1)
	{
		if (!(*buf = ft_makeline(*buf, line, i)))
			return (-1);
		return (1);
	}
	return (0);
}

int		left_buf(char **buf, char **line)
{
	int	res;

	if (gnl_strlen(*buf) != 0)
	{
		res = check_newline(buf, line);
		if (res == 1 || res == -1)
			return (res);
		else
			*line = *buf;
		*buf = NULL;
		return (0);
	}
	if (*buf)
	{
		*line = *buf;
		*buf = NULL;
	}
	else
	{
		if (!(*line = (char *)malloc(1)))
			return (-1);
		(*line)[0] = '\0';
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			byte;
	static char *buf[10240];
	char		str[BUFFER_SIZE + 1];
	char		*temp;

	if (!line || read(fd, "", 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((byte = read(fd, str, BUFFER_SIZE)) > 0)
	{
		str[byte] = '\0';
		if (!buf[fd])
			if (!(buf[fd] = gnl_strdup("")))
				return (-1);
		if (!(temp = gnl_strjoin(buf[fd], str)))
			return (-1);
		free(buf[fd]);
		buf[fd] = temp;
		byte = check_newline(&buf[fd], line);
		if (byte == 1 || byte == -1)
			return (byte);
	}
	return (left_buf(&buf[fd], line));
}
