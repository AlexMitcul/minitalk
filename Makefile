
CC =	cc
FLAGS =	-Wall -Wextra -Werror

NAME =	minitalk

all: $(NAME)

$(NAME): server client

server:
	$(CC) $(FLAGS) server.c -o server

client:
	$(CC) $(FLAGS) client.c -o client

clean:
	rm -f *.o

fclean: clean
	rm -f client server

re: fclean all
