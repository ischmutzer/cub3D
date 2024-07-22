/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:28:05 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/07 20:28:11 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			ptr = s;
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)ptr);
}
/*
int	main()
{
	const char *str = "lord have mercy";
	char target = 'e';
	
	char *lastOccurrence = strrchr(str, target);
	
	if (lastOccurrence != NULL)
	{
    		printf("'%c'%ld\n", target, lastOccurrence - str);
	} 
	else
	{
	    printf("it aint here");
	}
}
*/
