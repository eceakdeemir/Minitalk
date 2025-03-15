/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:31:16 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/15 11:23:44 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_handler(int param, siginfo_t *info, void *context)
{
	static int				bit_i;
	static unsigned char	text;

	(void)context;
	(void)info;
	if (param == SIGUSR1)
	{
		text |= (1 << (7 - bit_i));
	}
	bit_i++;
	if (bit_i == 8)
	{
		if (text != '\0')
			write(1, &text, 1);
		bit_i = 0;
		text = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					server_pid;

	server_pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = my_handler;
	ft_printf("server '%d' started\n", server_pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(0);
	else if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(0);
	while (42)
		pause();
	return (0);
}
