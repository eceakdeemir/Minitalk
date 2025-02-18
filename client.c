#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void send_character(char character, pid_t server_id)
{
	int bit_i;
	int bit;

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
void sending_str(char *str, pid_t server_id)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		send_character(str[i], server_id);
		i++;
	}
	//send_character(0, server_id);	
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (1);

	char *signal;
	pid_t server_id;

	signal = av[2];
	server_id = atoi(av[1]);
	sending_str(signal, server_id);
	return (0);
}
