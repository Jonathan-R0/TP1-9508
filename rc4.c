#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "rc4.h"

void swap(unsigned char *s, unsigned int coef1, unsigned int coef2){
    unsigned char temp = s[coef1];
    s[coef1] = s[coef2];
    s[coef2] = temp;
}

int rc4_cipher_init(rc4_cipher_t* cipher, unsigned char* key){

	if (cipher == NULL || key == NULL) return -1;
	cipher->key = key;
	cipher->a = cipher->b = 0;
	unsigned int len = (unsigned int)strlen((char*)key);
	
	unsigned int i, j;
    for (i = 0; i < 256; i++) cipher->S[i] = (char) i; 

    for (i = j = 0; i < 256; i++) {
        j = (j + key[i % len] + cipher->S[i]) & 255;
        swap(cipher->S, i, j);
    }

	return 0;
}

unsigned char randInt(rc4_cipher_t* cipher){

	if (cipher == NULL) return -1;
   
	unsigned int i = cipher->a; // Con estas variables evitamos
	unsigned int j = cipher->b; // tantos accesos a memoria.
	
	i = (i + 1) & 255;
    j = (j + cipher->S[i]) & 255;

    swap(cipher->S, i, j);
	
	cipher->a = i;
	cipher->b = j;

    return cipher->S[(cipher->S[i] + cipher->S[j]) & 255];
}

int rc4_decode(rc4_cipher_t* cipher, unsigned char string[]){
	return rc4_encode(cipher, string);
}

int rc4_encode(rc4_cipher_t* cipher, unsigned char string[]){
	if (cipher == NULL || string == NULL) return -1;

	unsigned int len = (unsigned int)strlen((char*)string);
	
	for (int k = 0; k < len; k++){
		string[k] ^= randInt(cipher);
	}
	
	return 0;
}
