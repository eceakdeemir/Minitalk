/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:37:57 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/02/19 14:38:19 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

int		ft_atoi(const char *str);
int		ft_nums_len(int n);
char	*ft_itoa(int n);
int		ft_strcmp(char *s1, char *s2);

#endif