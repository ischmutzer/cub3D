/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:03:08 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/25 11:03:10 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_print_check(char c, va_list *args, int *len)
{
	if (c == 's')
		ft_str(va_arg(*args, char *), len);
	else if (c == 'd' || c == 'i')
		ft_num(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unsigned_num(va_arg(*args, unsigned int), len);
	else if (c == 'c')
		ft_putchar_len((char)va_arg(*args, int), len);
	else if (c == '%')
		ft_putchar_len('%', len);
	else if (c == 'X')
		ft_printhex_cap(va_arg(*args, unsigned int), len);
	else if (c == 'x')
		ft_printhehex(va_arg(*args, unsigned int), len);
	else if (c == 'p')
		ft_print_address(va_arg(*args, void *), len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!string)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_print_check(string[i], &args, &len);
			i++;
		}
		else
		{
			ft_putchar_len((char)string[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>
int	main()
{
	int	num;
	
	num = ft_printf("hello %x\n", -17);
	printf("%x", -17);
	//ft_printf("num of char: %i", num);
}*/
/*
# include "ft_printf.h"
# include "stdio.h"

int main(void) {
    int io;
    int ic;
    int i = -2147483;
    char *blub = "hallo";

    ic = ft_printf(0);
    io = printf(0);
    if (io == ic)
        printf("check\n");
    else 
        printf("nope\n");
    int j = 0;
    ic = ft_printf("%d%i%d%i%d%i%d%i%i%i%i%d\n", j,j,j,j,j,j,j,j,j,j,j,j);
    io = printf("%d%i%d%i%d%i%d%i%i%i%i%d\n", j,j,j,j,j,j,j,j,j,j,j,j);
    if (io == ic)
        printf("check\n");
    else 
        printf("nope\n");
}*/
