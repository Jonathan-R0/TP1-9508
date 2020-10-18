// Copyright [2020]<Jonathan David Rosenblatt>
#ifndef COMMON_CIPHER_H_
#define COMMON_CIPHER_H_

#include "common_client_tda.h"

int cipher_and_send_cesar(client_t* self, unsigned char* key);
int cipher_and_send_vigenere(client_t* self, unsigned char* key);
int cipher_and_send_rc4(client_t* self, unsigned char* key);

#endif  // COMMON_CIPHER_H_
