/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexedecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:10:35 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/01 16:28:20 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_lower(unsigned long number)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (number > 15)
	{
		i += ft_hex_lower(number / 16);
		if (number >= 16)
			number = number % 16;
	}
	if (number <= 15)
		i += ft_putchar(hex[number % 16]);
	return (i);
}

int	ft_hex_upper(unsigned long number)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (number > 15)
	{
		i += ft_hex_upper(number / 16);
		if (number >= 16)
			number = number % 16;
	}
	if (number <= 15)
		i += ft_putchar(hex[number % 16]);
	return (i);
}
