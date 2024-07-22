/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:55:49 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/11 20:55:53 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*memory;

	total = nmemb * size;
	memory = malloc(total);
	if (memory != NULL)
	{
		ft_memset(memory, 0, total);
	}
	else if (memory == NULL)
	{
		return (NULL);
	}
	return (memory);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int size = 5;
    array = (int *)ft_calloc(size, sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);

    return 0;
}
*/
