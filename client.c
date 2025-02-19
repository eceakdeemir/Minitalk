/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:31:06 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/02/19 14:33:43 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_character(char character, pid_t server_id)
{
	int	bit_i;
	int	bit;

	bit_i = 7;
	while (bit_i >= 0)
	{
		usleep(100);
		bit = (character >> bit_i) & 1;
		if (bit == 1)
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
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
		perror("wrong pid");
		exit(1);
	}
	return (server_id_int);
}

int	main(int ac, char **av)
{
	char	*signal;
	char	*server_id;
	pid_t	server_pid;

	if (ac != 3)
		return (1);
	signal = av[2];
	server_id = av[1];
	server_pid = server_id_control(server_id);
	if (server_pid)
		sending_str(signal, server_pid);
	return (0);
}
