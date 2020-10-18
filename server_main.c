// Copyright [2020]<Jonathan David Rosenblatt>
#include <stdio.h>
#include <string.h>

#include "common_arginfo.h"
#include "common_decipher.h"
#include "common_server_tda.h"
#include "common_socket.h"

#define BUF_SIZE 65
#define ERR_ARG_NRO "Error, argumento inválido.\n"
#define CESAR_CIPHER "cesar"
#define VIGENERE_CIPHER "vigenere"
#define RC4_CIPHER "rc4"

static int decipher_and_recv(server_t* self, char* method, unsigned char* key) {
  if (strcmp(CESAR_CIPHER, method) == 0) {
    return decipher_and_recv_cesar(self, key);
  } else if (strcmp(VIGENERE_CIPHER, method) == 0) {
    return decipher_and_recv_vigenere(self, key);
  } else if (strcmp(RC4_CIPHER, method) == 0) {
    return decipher_and_recv_rc4(self, key);
  }
  return -1;  // No era ninguno de los habilitados.
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    fprintf(stderr, ERR_ARG_NRO);
    return 1;
  }

  arginfo_t arginfo;
  server_t self;

  // PONER MENSAJES DE ERROR EN CADA IF.
  if (!arginfo_init(&arginfo, argc, argv)) {
    return 1;
  } else if (server_init(&self) == -1) {
    return 1;
  } else if (server_connect(&self, arginfo.port) == -1) {
    return 1;
  } else if (decipher_and_recv(&self, arginfo.method,
                               (unsigned char*)arginfo.key) == -1) {
    return 1;
  } else if (server_destroy(&self) == -1) {
    return 1;
  }
  return 0;
}
