// Copyright [2020]<Jonathan David Rosenblatt>
#ifndef CLIENT_TDA_H_
#define CLIENT_TDA_H_

#include "common_socket.h"

typedef struct client{
    socket_t mysocket;
}client_t;

/*
 * Inicializa el tda client y sus correspondiente socket asociado.
 * Precondiciones: self != NULL.
 * Postcondiciones: deja el socket asociado inicializado. Devuelve
 * -1 en caso de error, 0 de lo contrario.
 */
int client_init(client_t* self);

/*
 * Destruye el elemento ingresado así como a sus atributos asociados.
 * Precondiciones: self != NULL.
 * Postcondiciones: libera los recursos que haya usado el elemento. Devuelve -1
 * en caso de error, 0 de lo contrario.
 */
int client_destroy(client_t* self);

/*
 * Intenta establecer una conexión con el puerto e ip dados. Si el bind, 
 * listen o accept fallan, se liberan los recursos.  
 * Precondiciones: self != NULL && port != NULL && ip != NULL.
 * Postcondiciones: deja los sockets inicializados para enviar y recibir datos
 * entre el cliente y servidor. Devuelve -1 en caso de error, 0 de lo contrario. 
 */
int client_connect(client_t* self, char* port, char* ip);

#endif  // SERVER_TDA_H_
