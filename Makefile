NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_A = printf/libftprintf.a

OBJ_PRINTF = printf/ft_writes.c printf/ft_numbers.c printf/ft_hexedecimal.c printf/ft_point.c printf/ft_strlen.c printf/ft_printf.c
SRV_OBJS = server.c
CL_OBJS = client.c client_functions.c

SRV_BNS_OBJ = server_bonus.c
CL_BNS_OBJ = client_bonus.c client_functions_bonus.c

all: server client

server: $(SRV_OBJS) $(OBJ_PRINTF)
	make -C printf
	$(CC) $(CFLAGS) $(SRV_OBJS) $(PRINTF_A) -o server

client: $(CL_OBJS) $(OBJ_PRINTF)
	make -C printf
	 $(CC) $(CFLAGS) $(CL_OBJS) $(PRINTF_A) -o client

bonus: server_bonus client_bonus

server_bonus: $(SRV_BNS_OBJ) $(OBJ_PRINTF)
	make -C printf
	$(CC) $(CFLAGS) $(SRV_BNS_OBJ) $(PRINTF_A) -o server_bonus

client_bonus: $(CL_BNS_OBJ) $(OBJ_PRINTF)
	make -C printf
	$(CC) $(CFLAGS) $(CL_BNS_OBJ) $(PRINTF_A) -o client_bonus

clean:
	rm -f *.o
	rm -f server client
	rm -f server_bonus client_bonus

fclean: clean
	make fclean -C printf

re: fclean all

.PHONY: all clean fclean re bonus
