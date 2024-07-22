/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:17:44 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/08 17:17:50 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		cr;
	unsigned int		i;

	p = (const unsigned char *)s;
	cr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == cr)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
int	main()
{
	const char *d = "amir alkaled";
	
	void	 *res = ft_memchr(d, 'r', 5);
	//void	 *res = memchr(d, 's', 5);
	
	if (res != NULL)
	{
		return (printf("the letter is occur "));
	}
	else 
		return (printf("it aint there shawty"));
	
}
*/
