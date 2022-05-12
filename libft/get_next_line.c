/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:34:14 by smischni          #+#    #+#             */
/*   Updated: 2022/04/03 15:58:40 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_and_save(int fd, char *saved);
static char	*ft_get_line(char *saved);
static char	*ft_update_saved(char *saved);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved[fd] = ft_read_and_save(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = ft_get_line(saved[fd]);
	saved[fd] = ft_update_saved(saved[fd]);
	return (line);
}

static char	*ft_read_and_save(int fd, char *saved)
{
	char	*buffer;
	int		readvalue;

	readvalue = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(saved, '\n') && readvalue != 0)
	{
		readvalue = read(fd, buffer, BUFFER_SIZE);
		if (readvalue == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (readvalue == 0)
			break ;
		buffer[readvalue] = '\0';
		saved = ft_strjoin_gnl(saved, buffer);
	}
	free(buffer);
	return (saved);
}

static char	*ft_get_line(char *saved)
{
	char	*line;
	int		i;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		line[i] = saved [i];
		i++;
	}
	return (line);
}

static char	*ft_update_saved(char *saved)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	tmp = ft_calloc((ft_strlen(saved) - i + 1), sizeof(char));
	if (!tmp)
		return (NULL);
	while (saved[i])
		tmp[j++] = saved[i++];
	free(saved);
	return (tmp);
}
