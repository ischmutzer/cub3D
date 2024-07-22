/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:46:19 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/25 10:46:22 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_num(int num, int *len)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	else if (num < 0)
	{
		ft_putchar_len('-', len);
		num = -num;
	}
	if (num > 9)
	{
		ft_num (num / 10, len);
	}
	num = num % 10 + 48;
	ft_putchar_len(num, len);
}

void	ft_unsigned_num(unsigned int num, int *len)
{
	if (num >= 10)
		ft_unsigned_num(num / 10, len);
	ft_putchar_len(num % 10 + '0', len);
}
