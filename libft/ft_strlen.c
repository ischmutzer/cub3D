/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:18:57 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/15 12:14:51 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
		char *str = "\0";
		printf("%zu\n", ft_strlen(str));
		printf("%zu", strlen(str));
		return 0;
}
*/
