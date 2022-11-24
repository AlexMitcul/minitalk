all: server client

server:
	gcc server.c -o server

client:
	gcc client.c -o client

clean:
	rm -f *.o

fclean: clean
	rm -f client server

re: fclean all
