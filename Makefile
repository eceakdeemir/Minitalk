CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_A = printf/libftprintf.a

OBJ_PRINTF = printf/ft_writes.c printf/ft_numbers.c printf/ft_hexedecimal.c printf/ft_point.c printf/ft_strlen.c printf/ft_printf.c
SRV_OBJS = server.c
CL_OBJS = client.c client_functions.c

all: server client

server: $(SRV_OBJS) $(OBJ_PRINTF)
	make -C printf
	$(CC) $(CFLAGS) $(SRV_OBJS) -o server

client: $(CL_OBJS) $(OBJ_PRINTF)
	make -C printf
	 $(CC) $(CFLAGS) $(CL_OBJS) -o client

