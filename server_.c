#include <stdio.h>

#include "common_arginfo.h"
#include "common_socket.h"

#define ERR_ARG_NRO "Error, argumento inválido.\n"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, ERR_ARG_NRO);
    return 1;
  }

  arginfo_t arginfo;
  if (!arginfo_init(&arginfo, argc, argv)) return 1;
  printf("Funciona con:\nmethod: %s\nkey: %s\nport: %s\nip: %s\n",
         arginfo.method, arginfo.key, arginfo.port, arginfo.ip);

  socket_t self;
  socket_t client;
  socket_init(&self);
  socket_init(&client);

  socket_bind(&self, arginfo.port);
  socket_listen(&self);
  socket_accept(&self, &client);

  /*****************************************************************/
  char msg[] = "Hello client";
  socket_send(&client, msg, 12);
  /*****************************************************************/
  char buf[13];
  socket_recv(&client, buf, 12);
  buf[12] = 0;
  printf("Recibí: %s\n", buf);
  /*****************************************************************/

  socket_destroy(&self);

  return 0;
}
