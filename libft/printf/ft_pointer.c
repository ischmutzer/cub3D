/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:36:04 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/30 17:36:06 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	address2(size_t add, int *len)
{
	if (add > 15)
	{
		address2(add / 16, len);
	}
	add = add % 16;
	if (add <= 9)
	{
		add = add + 48;
		ft_putchar_len(add, len);
	}
	else
	{
		add = add + 'a' - 10;
		ft_putchar_len(add, len);
	}
}

void	ft_print_address(void *ptr, int *len)
{
	size_t	add;

	if (ptr == 0)
	{
		ft_str("(nil)", len);
		return ;
	}
	add = (size_t)ptr;
	ft_str("0x", len);
	address2(add, len);
}
