all: server client

server: server.c
		gcc -o server server.c -levent -ggdb -O0
client:
		gcc -o client client.c -levent -ggdb -O0
clean: 
		rm server client

