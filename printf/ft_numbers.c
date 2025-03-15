/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:10:44 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 22:06:46 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long number)
{
	int	i;

	i = 0;
	if (number < 0)
	{
		i += ft_putchar('-');
		number *= -1;
	}
	if (number > 9)
	{
		i += ft_putnbr(number / 10);
		i += ft_putchar((number % 10 + '0'));
	}
	else
		i += ft_putchar((number % 10 + '0'));
	return (i);
}
