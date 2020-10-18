// Copyright [2020]<Jonathan David Rosenblatt>
#ifndef COMMON_SERVER_TDA_H_
#define COMMON_SERVER_TDA_H_

#include "common_socket.h"

typedef struct server {
  socket_t mysocket;
  socket_t client;
} server_t;

/*
 * Inicializa el tda server y sus correspondientes sockets asociados.
 * Precondiciones: self != NULL.
 * Postcondiciones: deja los sockets asociados inicializados. Devuelve
 * -1 en caso de error, 0 de lo contrario.
 */
int server_init(server_t* self);

/*
 * Destruye el elemento ingresado así como a sus atributos asociados.
 * Precondiciones: self != NULL.
 * Postcondiciones: libera los recursos que haya usado el elemento. Devuelve -1
 * en caso de error, 0 de lo contrario.
 */
int server_destroy(server_t* self);

/*
 * Intenta establecer una conexión con el puerto dado. Si el bind, listen o
 * accept fallan, se liberan los recursos.
 * Precondiciones: self != NULL && port != NULL.
 * Postcondiciones: deja los sockets inicializados para enviar y recibir datos
 * entre el cliente y servidor. Devuelve -1 en caso de error, 0 de lo contrario.
 */
int server_connect(server_t* self, char* port);

int server_recv(server_t* self, char buf[], int bugLen);

#endif  // COMMON_SERVER_TDA_H_
