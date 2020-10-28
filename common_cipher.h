// Copyright [2020]<Jonathan David Rosenblatt>
#ifndef COMMON_CIPHER_H_
#define COMMON_CIPHER_H_

#include "common_cesar.h"
#include "common_rc4.h"
#include "common_vigenere.h"

typedef union cipher {
  cesar_cipher_t cesar;
  vigenere_cipher_t vigenere;
  rc4_cipher_t rc4;
} generico_t;

#endif  // COMMON_CIPHER_H_