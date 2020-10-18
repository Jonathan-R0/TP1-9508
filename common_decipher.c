// Copyright [2020]<Jonathan David Rosenblatt>

#include "common_decipher.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_cesar.h"
#include "common_file_reader.h"
#include "common_rc4.h"
#include "common_server_tda.h"
#include "common_vigenere.h"

#define BYTES_A_ESCRIBIR 65

int decipher_and_recv_cesar(server_t* self, unsigned char* key) {
  if (self == NULL || key == NULL) return -1;
  unsigned char msg[BYTES_A_ESCRIBIR];
  int read = -1;
  cesar_cipher_t decipher;
  if (cesar_cipher_init(&decipher,
                        (unsigned int)strtol((char*)key, NULL, 10)) == -1)
    return -1;
  while ((read = server_recv(self, (char*)msg, BYTES_A_ESCRIBIR - 1)) != 0) {
    if (read == -1 || cesar_decode(&decipher, msg, read) == -1) {
      fprintf(stderr, "Sending or reading error\n");
      return -1;
    }
    printf("%s", msg);
  }
  return 0;
}

int decipher_and_recv_vigenere(server_t* self, unsigned char* key) {
  if (self == NULL || key == NULL) return -1;
  unsigned char msg[BYTES_A_ESCRIBIR];
  int read = -1;
  vigenere_cipher_t decipher;
  if (vigenere_cipher_init(&decipher, key) == -1) return -1;
  while ((read = server_recv(self, (char*)msg, BYTES_A_ESCRIBIR - 1)) != 0) {
    if (read == -1 || vigenere_decode(&decipher, msg, read) == -1) {
      fprintf(stderr, "Sending or reading error\n");
      return -1;
    }
    printf("%s", msg);
  }
  return 0;
}

int decipher_and_recv_rc4(server_t* self, unsigned char* key) {
  if (self == NULL || key == NULL) return -1;
  unsigned char msg[BYTES_A_ESCRIBIR];
  int read = -1;
  rc4_cipher_t decipher;
  if (rc4_cipher_init(&decipher, key) == -1) return -1;
  while ((read = server_recv(self, (char*)msg, BYTES_A_ESCRIBIR - 1)) != 0) {

	for (int k = 0; k < sizeof(msg) - 1; k++) fprintf(stderr,"%02x ",msg[k]);
	printf("\n");

    if (read == -1 || rc4_decode(&decipher, msg, read) == -1) {
      fprintf(stderr, "Sending or reading error\n");
      return -1;
    }
    printf("%s", msg);
  }
  return 0;
}
