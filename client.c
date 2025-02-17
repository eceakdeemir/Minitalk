
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void send_character(char character, pid_t si_pid)
{
	int bit_i;
	int bit;

	bit_i = 7;
	while (bit_i >= 0)
	{
		bit = (character >> bit_i) & 1;
		printf("%d\n", bit);
		if (bit == 1)
			kill(si_pid, SIGUSR1);
		else
			kill(si_pid, SIGUSR2);
		bit_i--;
	}
}
void sending_str(char *str, pid_t si_pid)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		send_character(str[i], si_pid);
		i++;
	}
	//send_character(0, si_pid);	
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (1);

	char *signal;
	int server_id;

	signal = av[2];
	server_id = atoi(av[1]);

	sending_str(signal, server_id);
	
}
