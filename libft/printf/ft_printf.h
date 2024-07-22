/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:49:49 by amalkhal          #+#    #+#             */
/*   Updated: 2023/09/30 17:49:52 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *string, ...);
void	ft_putchar_len(char c, int *len);
void	ft_str(char *args, int *len);
void	ft_num(int num, int *len);
void	ft_unsigned_num(unsigned int num, int *len);
void	ft_printhex_cap(unsigned int num, int *len);
void	ft_printhehex(unsigned int num, int *len);
void	ft_print_address(void *ptr, int *len);
#endif
