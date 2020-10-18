// Copyright [2020]<Jonathan David Rosenblatt>

#include "client_cipher.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "common_cesar.h"
#include "common_client_tda.h"
#include "common_file_reader.h"
#include "common_rc4.h"
#include "common_vigenere.h"

#define ARCHIVO_A_LEER stdin
#define BYTES_A_LEER 65

int cipher_and_send_cesar(client_t* self, unsigned char* key) {
  if (self == NULL || key == NULL) return -1;
  unsigned char msg[BYTES_A_LEER];
  int read = -1;
  cesar_cipher_t cipher;
  if (cesar_cipher_init(&cipher, key) == -1)
    return -1;
  while ((read = read_from_file_to_buf((char*)msg, BYTES_A_LEER - 1,
         ARCHIVO_A_LEER)) != 0) {
    if (read == -1 || cesar_encode(&cipher, msg) == -1 ||
        client_send(self, (char*)msg, read) == -1) {
      fprintf(stderr, "%s\n", strerror(errno));
      return -1;
    }
  }
  return 0;
}

int cipher_and_send_vigenere(client_t* self, unsigned char* key) {
  if (self == NULL || key == NULL) return -1;
  unsigned char msg[BYTES_A_LEER];
  int read = -1;
  vigenere_cipher_t cipher;
  if (vigenere_cipher_init(&cipher, key) == -1) return -1;
  while ((read = read_from_file_to_buf((char*)msg, BYTES_A_LEER - 1,
         ARCHIVO_A_LEER)) != 0) {
    if (read == -1 || vigenere_encode(&cipher, msg) == -1 ||
        client_send(self, (char*)msg, read) == -1) {
      fprintf(stderr, "%s\n", strerror(errno));
      return -1;
    }
  }
  return 0;
}

int cipher_and_send_rc4(client_t* self, unsigned char* key) {
  if (self == NULL || key == NULL) return -1;
  unsigned char msg[BYTES_A_LEER];
  int read = -1;
  rc4_cipher_t cipher;
  if (rc4_cipher_init(&cipher, key) == -1) return -1;
  while ((read = read_from_file_to_buf((char*)msg, BYTES_A_LEER - 1,
         ARCHIVO_A_LEER)) != 0) {
    if (read == -1 || rc4_encode(&cipher, msg) == -1 ||
        client_send(self, (char*)msg, read) == -1) {
      fprintf(stderr, "%s\n", strerror(errno));
      return -1;
    }
  }
  return 0;
}
