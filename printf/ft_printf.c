/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:10:50 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 21:53:15 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_helper(va_list *arg, const char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (str[i] == 'd' || str[i] == 'i')
		len += ft_putnbr(va_arg(*arg, int));
	if (str[i] == 'u')
		len += ft_putnbr(va_arg(*arg, unsigned int));
	if (str[i] == 'c')
		len += ft_putchar(va_arg(*arg, int));
	if (str[i] == 's')
		len += ft_putstr(va_arg(*arg, char *));
	if (str[i] == 'p')
		len += ft_point(va_arg(*arg, unsigned long));
	if (str[i] == 'x')
		len += ft_hex_lower(va_arg(*arg, unsigned int));
	if (str[i] == 'X')
		len += ft_hex_upper(va_arg(*arg, unsigned int));
	if (str[i] == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			len += ft_helper(&arg, &str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
