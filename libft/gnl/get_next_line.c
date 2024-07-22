/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:41:00 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/26 16:21:46 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

void	liberator(char **imprisoned_ptr)
{
	if (imprisoned_ptr)
	{
		free(*imprisoned_ptr);
		*imprisoned_ptr = NULL;
	}
}

void	*ft_memset_gnl(void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc_gnl(size_t num, size_t size)
{
	void	*buffer;
	size_t	bytesize;

	if (size == 0 || num == 0)
		return (malloc(0));
	bytesize = num * size;
	if (bytesize / num != size || bytesize > 2147483647)
		return (NULL);
	buffer = malloc(bytesize);
	if (buffer == NULL)
		return (NULL);
	ft_memset_gnl(buffer, '\0', bytesize);
	return (buffer);
}

static char	*readme(char **rawstr, int fd)
{
	int		bytes_read;
	char	*tinybuffer;

	tinybuffer = (char *)ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	if (tinybuffer == NULL)
	{
		liberator(rawstr);
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr_gnl(tinybuffer, '\n') && (bytes_read > 0))
	{
		bytes_read = read(fd, tinybuffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (liberator(&tinybuffer), liberator(rawstr), NULL);
		if (bytes_read == 0)
			break ;
		tinybuffer[bytes_read] = '\0';
		*rawstr = ft_strjoin_gnl(*rawstr, tinybuffer);
		if (*rawstr == NULL)
			return (NULL);
	}
	liberator(&tinybuffer);
	return (*rawstr);
}

char	*get_next_line(int fd, int mode)
{
	char		*cookeds;
	char		*tmp;
	static char	*rawstr = NULL;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0 || mode == 1)
		return (free(rawstr), rawstr = NULL, NULL);
	rawstr = readme(&rawstr, fd);
	if (rawstr == NULL)
		return (NULL);
	len = linlen(rawstr);
	cookeds = ft_substr_gnl(rawstr, 0, len);
	if (cookeds == NULL)
		return (liberator(&rawstr), NULL);
	if (((ft_strlen_gnl(rawstr) + 1) - len) > 0)
	{
		tmp = ft_substr_gnl(rawstr, len, ((ft_strlen_gnl(rawstr) + 1) - len));
		if (tmp == NULL)
			return (liberator(&rawstr), liberator(&cookeds), NULL);
		liberator(&rawstr);
		rawstr = tmp;
	}
	else
		liberator(&rawstr);
	return (cookeds);
}

//amr

/* char	*read_line(int fd, char *ncall)
{
	int		b_read;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	b_read = 1;
	while (!ft_strchrgnl(ncall, '\n') && b_read != 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buf);
			free(ncall);
			return (NULL);
		}
		buf[b_read] = '\0';
		ncall = ft_strjoin_g(ncall, buf);
	}
	free(buf);
	return (ncall);
}

char	*ft_get_line(char *ncall)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!ncall[i])
		return (NULL);
	while (ncall[i] != '\0' && ncall[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(ncall), NULL);
	while (j < i)
	{
		line[j] = ncall[j];
		j++;
	}
	if (ncall[i] == '\n')
	{
		line[i] = ncall[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*last_read(char *ncall)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (ncall[i] && ncall[i] != '\n')
		i++;
	if (!ncall[i])
	{
		free(ncall);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(ncall) - i + 1));
	if (!temp)
		return (free(ncall), NULL);
	i++;
	while (ncall[i])
		temp[j++] = ncall[i++];
	temp[j] = '\0';
	free(ncall);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*ncall;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ncall = read_line(fd, ncall);
	if (!ncall)
		return (NULL);
	line = ft_get_line(ncall);
	ncall = last_read(ncall);
	return (line);
} */
