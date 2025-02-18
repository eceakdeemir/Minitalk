#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void my_handler(int param, siginfo_t *info, void *context)
{
    (void)context;
	(void)info;
    //printf("signal buradan geldi: %d, gelen signal: %d\n", info->si_pid, param);

	static int bit_i;
	static unsigned char text;

	if (param == SIGUSR1)
	{
		text |= (1 << (7 - bit_i));
		//printf("%d\n", text);
	}
	bit_i++;
	if (bit_i == 8)
	{
		if (text != '\0')
			write(1,&text,1);
		bit_i = 0;
		text = 0;
	}
    // kill(info->si_pid, SIGUSR1);
}


int main()
{
    struct sigaction sa;
    int server_pid;

    server_pid = getpid();
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = my_handler;
    
    printf("server '%d' started\n", server_pid);

    if(sigaction(SIGUSR1, &sa, NULL) == -1)
    {
		perror("ERRORRRRRRR\n");
        exit(404);
	}
	else if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("ERRORRRRRRR\n");
        exit(404);
	}
	while(42)
		pause();
	return (0);
}