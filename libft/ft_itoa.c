/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:48:17 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/17 22:48:19 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digigt_count(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static int	ft_bool(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		d_count;
	char	*res;

	sign = ft_bool(n);
	d_count = digigt_count(n) + sign;
	res = (char *)malloc(sizeof(char) * (d_count + 1));
	if (res == NULL)
		return (NULL);
	res[d_count] = '\0';
	if (sign)
	{
		*res = '-';
		res[--d_count] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (d_count-- - sign)
	{
		res[d_count] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}
/*
int		main()
{
	char	*str = ft_itoa(-2147483648);
	printf("the string is : %s\n", str);
	return 0;
}
*/
