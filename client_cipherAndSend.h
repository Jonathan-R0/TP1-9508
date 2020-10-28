// Copyright [2020]<Jonathan David Rosenblatt>
#ifndef CLIENT_CIPHERANDSEND_H_
#define CLIENT_CIPHERANDSEND_H_

#include "client_tda.h"

/*
 * Dado el cliente y clave recibido, encripta con el algoritmo de cesar todo lo
 * que ingrese por stdin y lo envía por el fd asociado al cliente dado.
 * Precondiciones: self != NULL && socket asociado incializado y conectado &&
 * key != NULL.
 * Postcondiciones: encripta y envía por red lo ingresado por stdin. Devuelve
 * -1 en caso de error, 0 de lo contrario.
 */
// int cipher_and_send_cesar(client_t* self, unsigned char* key);

/*
 * Dado el cliente y clave recibido, encripta con el algoritmo de vigenere
 * todo lo que ingrese por stdin y lo envía por el fd asociado al cliente dado.
 * Precondiciones: self != NULL && socket asociado incializado y conectado &&
 * key != NULL.
 * Postcondiciones: encripta y envía por red lo ingresado por stdin. Devuelve
 * -1 en caso de error, 0 de lo contrario.
 */
// int cipher_and_send_vigenere(client_t* self, unsigned char* key);

/*
 * Dado el cliente y clave recibido, encripta con el algoritmo de rc4 todo lo
 * que ingrese por stdin y lo envía por el fd asociado al cliente dado.
 * Precondiciones: self != NULL && socket asociado incializado y conectado &&
 * key != NULL.
 * Postcondiciones: encripta y envía por red lo ingresado por stdin. Devuelve
 * -1 en caso de error, 0 de lo contrario.
 */
// int cipher_and_send_rc4(client_t* self, unsigned char* key);

int cipher_and_send_info(client_t* self, unsigned char* key);

#endif  // CLIENT_CIPHERANDSEND_H_
