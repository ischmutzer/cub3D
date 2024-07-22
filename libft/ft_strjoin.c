/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:06:13 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/22 15:55:41 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*new_str;
	unsigned int		i;
	unsigned int		j;

	i = -1;
	j = 0;
	if (!s1)
		return (ft_strdup((char *) s2));
	if (!s2)
		return (ft_strdup((char *) s1));
	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		new_str[i] = s1[i];
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
/*
#include <stdio.h>
int	main()
{
	char const s[] = "hello shawty";
	char const b[] = "hello shawty";
	
	char *sub = ft_strjoin(s, b);
	
	printf("%s", sub);
}
*/
