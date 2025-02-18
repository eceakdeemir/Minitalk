

SRV_OBJS = server.c
CL_OBJS = client.c

server: $(SRV_OBJS)
	gcc -Wall -Wextra -Werror server.c -o server

client: $(CL_OBJS)
	gcc -Wall -Wextra -Werror client.c -g -o client

