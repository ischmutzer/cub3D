/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:29:21 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/14 12:29:26 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == (-2147483648))
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = n * (-1);
		write (fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		n = n % 10 + 48;
		write (fd, &n, 1);
	}
}
/*
int	main()
{
	ft_putnbr_fd(-2147483648, 1);
}
*/
