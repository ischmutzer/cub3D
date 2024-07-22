/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:47:01 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/09 11:47:08 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n > 0)
	{
		if (*p1 != *p2)
		{
			return ((int)(*p1 - *p2));
		}
		p1++;
		p2++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	const char *s = "hello";
	const char *d = "hellb";
	
	printf("%d\n", ft_memcmp(s, d, 5));
	printf("%d", memcmp(s, d, 5));
}
*/
