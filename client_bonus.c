/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:31:06 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/15 16:20:59 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_signal_status = 0;

void	listening_signal(int signum)
{
	if (signum == SIGUSR1)
		g_signal_status = 1;
	else
		exit(1);
}

void	send_character(char character, pid_t server_id)
{
	int	bit_i;
	int	bit;

	bit_i = 7;
	while (bit_i >= 0)
	{
		g_signal_status = 0;
		bit = (character >> bit_i) & 1;
		if (bit == 1)
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		while (g_signal_status == 0)
			pause();
		bit_i--;
	}
}

void	sending_str(char *str, pid_t server_id)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_character(str[i], server_id);
		i++;
	}
}

pid_t	server_id_control(char *id)
{
	char	*tmp;
	pid_t	server_id_int;

	server_id_int = ft_atoi(id);
	tmp = ft_itoa(server_id_int);
	if (ft_strcmp(tmp, id) != 0)
	{
		ft_printf("wrong pid");
		exit(1);
	}
	return (server_id_int);
}

int	main(int ac, char **av)
{
	char	*string_signal;
	char	*server_id;
	pid_t	server_pid;

	if (ac != 3)
		return (1);
	string_signal = av[2];
	server_id = av[1];
	server_pid = server_id_control(server_id);
	signal(SIGUSR1, listening_signal);
	if (server_pid)
		sending_str(string_signal, server_pid);
	send_character('\0', server_pid);
	return (0);
}
