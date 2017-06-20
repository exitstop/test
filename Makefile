all: server

server: server.c
		gcc -ggdb -O0 -o server server.c -levent
clean: 
		rm server
