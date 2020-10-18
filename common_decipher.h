// Copyright [2020]<Jonathan David Rosenblatt>
#ifndef COMMON_DECIPHER_H_
#define COMMON_DECIPHER_H_

#include "common_server_tda.h"

/*
 * Dado el cliente y clave recibido, desencripta con el algoritmo de cesar
 * todo que ingrese por red y lo escribe por stdin.
 * Precondiciones: self != NULL && socket asociado incializado y configurado
 * && key != NULL.
 * Postcondiciones: desencripta lo que recibe por red y lo escribe por stdin. 
 * Devuelve  -1 en caso de error, 0 de lo contrario.
 */
int decipher_and_recv_cesar(server_t* self, unsigned char* key);

/*
 * Dado el cliente y clave recibido, desencripta con el algoritmo de vigenere
 * todo que ingrese por red y lo escribe por stdin.
 * Precondiciones: self != NULL && socket asociado incializado y configurado
 * && key != NULL.
 * Postcondiciones: desencripta lo que recibe por red y lo escribe por stdin. 
 * Devuelve  -1 en caso de error, 0 de lo contrario.
 */
int decipher_and_recv_vigenere(server_t* self, unsigned char* key);

/*
 * Dado el cliente y clave recibido, desencripta con el algoritmo de rc4
 * todo que ingrese por red y lo escribe por stdin.
 * Precondiciones: self != NULL && socket asociado incializado y configurado
 * && key != NULL.
 * Postcondiciones: desencripta lo que recibe por red y lo escribe por stdin. 
 * Devuelve  -1 en caso de error, 0 de lo contrario.
 */
int decipher_and_recv_rc4(server_t* self, unsigned char* key);

#endif  // COMMON_DECIPHER_H_
