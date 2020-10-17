// Copyright [2020]<Jonathan David Rosenblatt>
#include <stdio.h>

#include "server_tda.h"
#include "common_socket.h"

#define QUEUE_SIZE 10
#define BUF_SIZE 65

int server_init(server_t* self){
	if (self == NULL || 
		socket_init(&self->mysocket) == -1 ||
		socket_init(&self->client) == -1)
		return -1;
	return 0;
}

int server_destroy(server_t* self){
	if (self == NULL ||
		socket_destroy(&self->mysocket) == -1 ||
		socket_destroy(&self->client) == -1)
		return -1;
	return 0;
}

int server_connect(server_t* self, char* port){
	if (self == NULL || port == NULL) return -1;

	if (socket_bind(&self->mysocket,port) == -1 ||
		socket_listen(&self->mysocket,QUEUE_SIZE) == -1 ||
		socket_accept(&self->mysocket,&self->client) == -1){
			server_destroy(self);
			return -1;
		}
	return 0;
}

int server_recv(server_t* self){

	int i = 0;
	char buf[BUF_SIZE+1];
	int bytes_read = -1;
	while (bytes_read != 0 && ++i < 10){
		if ((bytes_read = socket_recv(&self->client,buf,BUF_SIZE)) == -1) {
			return -1;
 		}
		buf[bytes_read] = 0;
		printf("%s",buf);
		if (bytes_read == 0){ 
			break;
		}
	}
	printf("\n");
	return 0;
}
