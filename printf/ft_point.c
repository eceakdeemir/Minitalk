/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:10:27 by ecakdemi          #+#    #+#             */
/*   Updated: 2024/12/08 14:39:14 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point(unsigned long c)
{
	int	i;

	i = 0;
	if (!c)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i += ft_putstr("0x");
	i += ft_hex_lower(c);
	return (i);
}
