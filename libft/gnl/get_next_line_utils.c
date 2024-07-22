/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:42:25 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/26 16:22:46 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

size_t	linlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (s[0] == '\n')
		return (1);
	while (s[i] != '\n' && s[i])
	{
		i++;
		if (s[i] == '\n')
			return (i + 1);
	}
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	c_;
	char	*result;
	char	*s_;

	i = 0;
	result = NULL;
	s_ = (char *) s;
	c_ = (char) c;
	while (s_[i] != '\0' || c_ == '\0')
	{
		if (s_[i] != c_)
			i++;
		else
		{
			result = s_ + i;
			break ;
		}
	}
	return (result);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (!s || !s[0])
		return (NULL);
	if (start >= ft_strlen_gnl(s) || len == 0)
	{
		subs = ft_calloc_gnl(1, sizeof(char));
		if (subs == NULL)
			return (NULL);
		return (subs);
	}
	if (len > ft_strlen_gnl(s + start))
		len = ft_strlen_gnl(s + start);
	subs = ft_calloc_gnl(len + 1, sizeof(char));
	if (subs == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		subs[i] = s[i + start];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t		papamericano;
	char		*str;
	size_t		i;
	size_t		e;

	i = 0;
	e = 0;
	papamericano = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	str = ft_calloc_gnl(papamericano + 1, sizeof(char));
	if (str == NULL)
		return (liberator(&s1), liberator(&s2), NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[e] != '\0')
	{
		str[i] = s2[e];
		e++;
		i++;
	}
	str[i] = '\0';
	return (liberator(&s1), str);
}

//amr

/* size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
} */

/* char	*ft_strchrgnl(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	char	*ns;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ns = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ns == NULL)
		return (free(s1), NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		ns[i] = s1[i];
	while (s2[j])
		ns[i++] = s2[j++];
	ns[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (free(s1), ns);
} */
