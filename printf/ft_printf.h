/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:01:25 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 21:58:07 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long number);
int	ft_hex_lower(unsigned long number);
int	ft_hex_upper(unsigned long number);
int	ft_percent(void);
int	ft_point(unsigned long c);
int	ft_strlen(char *str);
int	ft_helper(va_list *arg, const char *str);
int	ft_printf(const char *str, ...);
#endif