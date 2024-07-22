/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:02:01 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/22 16:37:49 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count + 1);
}

static char	*ft_worddup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	free_array_revers(char **ret, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(ret[j]);
		j++;
	}
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			strs[k++] = ft_worddup(s + j, i - j);
		else
			strs[k++] = ft_worddup("", 1);
		if (!strs[k - 1])
			return (free_array_revers(strs, k), NULL);
		if (s[i])
			i++;
	}
	return (strs[k] = NULL, strs);
}

/* int	count(char const *s, char c)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (!s[i])
			break ;
		num++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (num);
}

int	search_next(char const *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start + i] != 0 && s[start + i] != c)
	{
		i++;
	}
	return (start + i);
}

char	*cut(char const *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(end - start + 1);
	if (!word)
		return (0);
	while (start + i < end)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**freedom(char **ret, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(ret[j]);
		j++;
	}
	free(ret);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		start;
	int		end;

	start = 0;
	i = 0;
	ret = (char **) malloc(sizeof(char *) * (count(s, c) + 1));
	if (!ret)
		return (0);
	ret[count(s, c)] = 0;
	while (i < count(s, c))
	{
		while (s[start] == c)
			start++;
		end = search_next(s, start, c);
		ret[i] = cut(s, start, end);
		if (ret[i] == 0)
			return (freedom(ret, i));
		start = end;
		i++;
	}
	return (ret);
} */

//amr

// static size_t	ft_count(char const *s, char c)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!*s)
// 		return (0);
// 	while (*s)
// 	{
// 		while (*s == c && *s)
// 			s++;
// 		if (*s)
// 			i++;
// 		while (*s != c && *s)
// 			s++;
// 	}
// 	return (i);
// }

// // static size_t	ft_strplace(const char *s, char c, size_t n)
// // {
// // 	while (s[n] != '\0' && s[n] != c)
// // 		n++;
// // 	return (n);
// // }

// char	**ft_split(char const *s, char c)
// {
// 	char	**lst;
// 	size_t	n;
// 	size_t	i;
// 	size_t	start;

// 	i = 0;
// 	n = 0;
// 	start = 0;
// 	lst = malloc((ft_count(s, c) + 2) * sizeof(char *));
// 	if (!s || !lst)
// 		return (NULL);
// 	while (s[n])
// 	{
// 		if (s[n] == c || s[n + 1] == '\0')
// 		{
// 			if (s[n] != c)
// 				n++;
// 			lst[i] = ft_substr(s, start, n - start);
// 			if (!lst[i++])
// 			{
// 				while (i > 0)
// 					free(lst[--i]);
// 				free(lst);
// 				return (NULL);
// 			}
// 			start = n + 1;
// 		}
// 		n++;
// 	}
// 	lst[i] = NULL;
// 	return (lst);
// }

/*
#include <stdio.h>
int main(void)
{
	char *input_string = "Hello,World,How,Are,You";
	char delimiter = ',';

	char **result = ft_split(input_string, delimiter);

	if (result == NULL)
    {
        printf("Splitting failed. Memory allocation error.\n");
        return 1;
    }

    int i = 0;
    while (result[i] != NULL)
    {
        printf("Word %d: %s\n", i, result[i]);
        i++;
    }
    return 0;
}
*/
