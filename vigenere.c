#include <string.h>
#include <stdio.h>
#include "vigenere.h"

int vigenere_encode(vigenere_cipher_t* cipher, unsigned char string[]){
	unsigned int n = (unsigned int)strlen((char*)string);
	unsigned int m = (unsigned int)strlen((char*)cipher->key);

	for (int i = 0; i < n; i++) printf("%d|",string[i]);
		printf("\n");
	for (int i = 0; i < m; i++) printf("%d|",cipher->key[i]);
		printf("\n");

	unsigned char buf[n];

	int max = m > n ? m : n;
	for (int i = 0; i < n; i++){
		unsigned int suma = string[i % n] + cipher->key[i % m];
		buf[i] = suma % 256;
	}

	for (int i = 0; i < n; i++) printf("%d|",buf[i]);
	printf("\nbuf: %s\n",buf);

	return 0;
}

int vigenere_cipher_init(vigenere_cipher_t* cipher, unsigned char* key){
	if (cipher == NULL || key == NULL) return -1;	
	cipher->key = key;
	cipher->len = (unsigned int)strlen((char*)key);
}
