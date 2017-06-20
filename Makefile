all: server client

server: server.c
		gcc -ggdb -O0 -o server server.c -levent
client:
		gcc -ggdb -O0 -o client client.c -levent
clean: 
		rm server client

