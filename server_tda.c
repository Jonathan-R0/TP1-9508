#include "server_tda.h"
#include "common_socket.h"

#define QUEUE_SIZE 10

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


