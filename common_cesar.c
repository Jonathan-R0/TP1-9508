// Copyright [2020]<Jonathan David Rosenblatt>
#include "common_cesar.h"

#include <stddef.h>
#include <string.h>

int cesar_cipher_init(cesar_cipher_t* cipher, unsigned int key) {
  if (cipher == NULL) return -1;
  cipher->shift = key;
  return 0;
}

int cesar_shift_bytes(int shift, unsigned char msg[], unsigned int msgLen) {
  if (msg == NULL) return -1;
  for (int i = 0; i < msgLen; i++) {
    unsigned int caracter = msg[i];
    if (caracter <= 256) {
      msg[i] = (caracter + shift) % 256;
    }
  }
  return 0;
}

int cesar_encode(cesar_cipher_t* cipher, unsigned char msg[]) {
  if (cipher == NULL || msg == NULL) return -1;
  return cesar_shift_bytes(((int)cipher->shift), msg,
                           (unsigned int)strlen((char*)msg));
}

int cesar_decode(cesar_cipher_t* cipher, unsigned char msg[],
                 unsigned int msgLen) {
  if (cipher == NULL || msg == NULL) return -1;
  return cesar_shift_bytes(-1 * ((int)cipher->shift), msg, msgLen);
}
