/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:40:59 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/06 15:41:01 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	cr;
	unsigned int	i;

	p = s;
	cr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p[i] = cr;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
int main() {
    char buffer[] = "can u be my pookie";
    memset(buffer, 'A', 10);
    printf("Buffer contents: %s\n", buffer);

    return 0;
}
*/
