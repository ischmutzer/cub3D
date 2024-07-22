/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:08 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/15 17:02:10 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f (i, s + i);
		i++;
	}
}
/*
#include <stdio.h>

void	f(unsigned int index, char *c)
{
    printf("Character at index %u: %c\n", index, *c);
}

int main() {
    char str[] = "Hello, world!";
    ft_striteri(str, f);
    return 0;
}
*/
