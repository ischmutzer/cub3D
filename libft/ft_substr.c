/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:09:25 by amalkhal          #+#    #+#             */
/*   Updated: 2023/12/06 14:13:14 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, size_t start, size_t len)
{
	size_t	str_len;
	char	*result;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str + start, len + 1);
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	char const *s = "hey i am a bitch and i go by the name wenlong";
	
	printf("%s", ft_substr(s, 6, 3));
}
*/
