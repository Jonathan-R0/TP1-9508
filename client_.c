#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "common_arginfo.h"
#include "common_socket.h"

#define BYTES_A_LEER 64
#define ERR_ARG_NRO "Error, argumento inválido.\n"

static void do_stuff_with_stdin(arginfo_t* info) {
  char buf[BYTES_A_LEER];
  size_t porLeer = BYTES_A_LEER;
  while (!feof(stdin)) {
    size_t leidos = fread(buf, 1, porLeer, stdin);
    buf[leidos] = '\0';
    //		printf("%s - %ld\n",buf,leidos);
  }
}

int main(int argc, char* argv[]) {
  if (argc != 5) {
    fprintf(stderr, ERR_ARG_NRO);
    return 1;
  }

  arginfo_t arginfo;
  if (!arginfo_init(&arginfo, argc, argv)) return 1;
  printf("Funciona con:\nmethod: %s\nkey: %s\nport: %s\nip: %s\n",
         arginfo.method, arginfo.key, arginfo.port, arginfo.ip);
  do_stuff_with_stdin(&arginfo);

  socket_t self;
  socket_init(&self);
  socket_connect(&self, arginfo.port, arginfo.ip);

  /*****************************************************************/
  char buf[13];
  socket_recv(&self, buf, 12);
  buf[12] = 0;
  printf("Recibí: %s\n", buf);
  /*****************************************************************/
  char msg[] = "Hello server";
  socket_send(&self, msg, 12);
  /*****************************************************************/

  socket_destroy(&self);

  return 0;
}
