/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:15:45 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/05 14:15:50 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst [i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int	main()
{
	char *s = "hello";
	char des[50];
	printf("%zu | %s", ft_strlcpy(des, s, 5), des);
}
*/
