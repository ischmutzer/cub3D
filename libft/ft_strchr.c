/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:01:25 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/07 15:01:27 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s++ == (char)c)
			return ((char *)--s);
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	const char *b = "my name jeff";
	int d = 'm';
	
	char *result = ft_strchr(b, d);
	
    	if (result != NULL)
    	{
        printf("%c", d);
    	} 
    	else
    	{
   	     return (0);
   	}
    	return 0;
}
*/
