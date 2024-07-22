/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:43:12 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/04 19:40:09 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	s = src;
	d = dest;
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else if (d > s)
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
		{
			*d-- = *s--;
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	const char s[] = "amir, yoy ";
	char d[] = "amiralkhaled";
	
	char *res = ft_memmove(d, s, 6);
	//char *re = memmove (d, s, 2);
	printf("%s\n", res);
	//printf("%s\n", re);
	
}
*/
