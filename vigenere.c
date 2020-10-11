#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "vigenere.h"

int vigenere_shift_bytes(vigenere_cipher_t* cipher, short estoyCifrando, 
						 unsigned char string[], unsigned int msgLen){

	unsigned int keyLen = (unsigned int)strlen((char*)cipher->key);
	// Para inicializar todo en cero en una sola operación.
	unsigned char* buf = calloc(sizeof(unsigned char),msgLen+1); 
	if (buf == NULL) return -1;
	int i; int j = cipher->lastKeyIndex;
	for (i = 0; i < msgLen; i++){
		unsigned int suma = string[i % msgLen] 
			              + estoyCifrando * cipher->key[j % keyLen];
		buf[i] = suma % 256; j++;
	}	
	strcpy(string,buf); // No es insegura ya que tienen el mismo largo
	cipher->lastKeyIndex += j;
	free(buf);
	return 0;
}

int vigenere_encode(vigenere_cipher_t* cipher, unsigned char string[]){
	if (cipher == NULL) return -1;
	return vigenere_shift_bytes(cipher, 1, string, (unsigned int)strlen((char*)string));	
}

int vigenere_decode(vigenere_cipher_t* cipher, unsigned char string[], unsigned int msgLen){
	if (cipher == NULL || string == NULL) return -1;	
	return vigenere_shift_bytes(cipher, -1, string, n);	
}

int vigenere_cipher_init(vigenere_cipher_t* cipher, unsigned char* key){
	if (cipher == NULL || key == NULL) return -1;	
	cipher->key = key;
	cipher->lastKeyIndex = 0;
}
