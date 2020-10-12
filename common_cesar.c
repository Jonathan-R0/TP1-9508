#include <string.h>
#include <stddef.h>
#include "common_cesar.h"

int cesar_cipher_init(cesar_cipher_t* cipher, unsigned int key){
	if (cipher == NULL) return -1;	
	cipher->shift = key;
	return 0;
}

int cesar_shift_bytes(int shift, unsigned char string[], unsigned int msgLen){
    // No aceptamos cadenas vacías ni NULLs.

	if (string == NULL) return -1;
    for (int i = 0; i < msgLen; i++){
        unsigned int caracter = string[i];
        if (caracter <= 256){
            string[i] = (caracter + shift) % 256;
        }
    }
    return 0;
}

int cesar_encode(cesar_cipher_t* cipher, unsigned char string[]){
    if (cipher == NULL || string == NULL) return -1;
	return cesar_shift_bytes(((int)cipher->shift),string,(unsigned int)strlen((char*)string));
}

int cesar_decode(cesar_cipher_t* cipher, unsigned char string[], unsigned int msgLen){
    if (cipher == NULL || string == NULL) return -1;
	return cesar_shift_bytes(-1*((int)cipher->shift),string,msgLen);
}
