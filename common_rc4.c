// Copyright [2020]<Jonathan David Rosenblatt>
#include "common_rc4.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

/*
 * Swappea los elementos de la posición "coef1" y "coef2" dentro del arreglo
 * recibido. Precondiciones: s != NULL && coef1,coef2 < strlen(s)
 * Postcondiciones: swappea los elementos, si el arreglo ingresado es NULL no
 * hace nada.
 */
static void _swap_chars(unsigned char* s, unsigned int coef1,
                        unsigned int coef2) {
  if (s == NULL) return;
  unsigned char temp = s[coef1];
  s[coef1] = s[coef2];
  s[coef2] = temp;
}

int rc4_cipher_init(rc4_cipher_t* cipher, unsigned char* key) {
  if (cipher == NULL || key == NULL) return -1;
  cipher->key = key;
  cipher->a = cipher->b = 0;
  unsigned int len = (unsigned int)strlen((char*)key);

  unsigned int i, j;
  for (i = 0; i < 256; i++) cipher->S[i] = (char)i;

  for (i = j = 0; i < 256; i++) {
    j = (j + key[i % len] + cipher->S[i]) & 255;
    _swap_chars(cipher->S, i, j);
  }

  return 0;
}

unsigned char randChar(rc4_cipher_t* cipher) {
  if (cipher == NULL) return -1;

  unsigned int i = cipher->a;  // Con estas variables evitamos
  unsigned int j = cipher->b;  // tantos accesos a memoria.

  i = (i + 1) & 255;
  j = (j + cipher->S[i]) & 255;

  _swap_chars(cipher->S, i, j);

  cipher->a = i;
  cipher->b = j;

  return cipher->S[(cipher->S[i] + cipher->S[j]) & 255];
}

int rc4_encode(rc4_cipher_t* cipher, unsigned char msg[]) {
  // Es necesario reiniciar el cipher para desencriptar.
  if (cipher == NULL || msg == NULL) return -1;
  return rc4_decode(cipher, msg, (unsigned int)strlen((char*)msg));
}

int rc4_decode(rc4_cipher_t* cipher, unsigned char msg[], unsigned int len) {
  if (cipher == NULL || msg == NULL) return -1;

  for (int k = 0; k < len; k++) {
    msg[k] ^= randChar(cipher);
  }
  return 0;
}
