/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:13:57 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/29 15:13:59 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex_cap(unsigned int n, int *len)
{
	if (n > 15)
		ft_printhex_cap(n / 16, len);
	n = n % 16;
	if (n <= 9)
	{
		n = n + 48;
		write (1, &n, 1);
		(*len)++;
	}
	else
	{
		n = n + 65 - 10;
		write (1, &n, 1);
		(*len)++;
	}
}

void	ft_printhehex(unsigned int n, int *len)
{
	if (n > 15)
		ft_printhehex(n / 16, len);
	n = n % 16;
	if (n <= 9)
	{
		n = n + 48;
		write (1, &n, 1);
		(*len)++;
	}
	else
	{
		n = n + 97 - 10;
		write (1, &n, 1);
		(*len)++;
	}
}
