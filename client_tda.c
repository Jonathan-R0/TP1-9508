#include "client_tda.h"
#include "common_socket.h"

#define QUEUE_SIZE 10

int client_init(client_t* self){
	if (self == NULL || 
		socket_init(&self->mysocket) == -1)
		return -1;
	return 0;
}

int client_destroy(client_t* self){
	if (self == NULL ||
		socket_destroy(&self->mysocket) == -1) 
		return -1;
	return 0;
}

int client_connect(client_t* self, char* port, char* ip){
	if (self == NULL || port == NULL || ip == NULL) return -1;

	if (socket_connect(&self->mysocket,port,ip) == -1){
		client_destroy(self);
		return -1;
	}
	return 0;
}


