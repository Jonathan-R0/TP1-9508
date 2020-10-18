// Copyright [2020]<Jonathan David Rosenblatt>
#ifndef COMMON_DECIPHER_H_
#define COMMON_DECIPHER_H_

#include "common_server_tda.h"

int decipher_and_recv_cesar(server_t* self, unsigned char* key);
int decipher_and_recv_vigenere(server_t* self, unsigned char* key);
int decipher_and_recv_rc4(server_t* self, unsigned char* key);

#endif  // COMMON_DECIPHER_H_
