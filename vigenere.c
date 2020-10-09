#include <string.h>
#include <stdio.h>
#include "vigenere.h"

int vigenere_shift_bytes(unsigned char* key, unsigned char string[], short estoyCifrando){
	unsigned int n = (unsigned int)strlen((char*)string);
	unsigned int m = (unsigned int)strlen((char*)key);

	for (int i = 0; i < n; i++) printf("%d|",string[i]);
		printf("\n");
	for (int i = 0; i < m; i++) printf("%d|",key[i]);
		printf("\n");

	unsigned char buf[n];
	int max = m > n ? m : n;

	for (int i = 0; i < n; i++){
		unsigned int suma = string[i % n] + estoyCifrando * key[i % m];
		buf[i] = suma % 256;
	}
	strcpy(string,buf); // No es insegura ya que tienen el mismo largo
	string[n] = '\0';   // y le pongo el fin de string manualmente.

	for (int i = 0; i < n; i++) printf("%d|",buf[i]);
	printf("\nbuf: %s\n",buf);

	return 0;
}

int vigenere_encode(vigenere_cipher_t* cipher, unsigned char string[]){
	if (cipher == NULL || string == NULL) return -1;
	return vigenere_shift_bytes(cipher->key, string, 1);	
}

int vigenere_decode(vigenere_cipher_t* cipher, unsigned char string[]){
	if (cipher == NULL || string == NULL) return -1;	
	return vigenere_shift_bytes(cipher->key, string, -1);	
}

int vigenere_cipher_init(vigenere_cipher_t* cipher, unsigned char* key){
	if (cipher == NULL || key == NULL) return -1;	
	cipher->key = key;
}
