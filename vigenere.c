#include <string.h>
#include <stdio.h>
#include "vigenere.h"

int vigerene_cipher_init(vigenere_cipher_t* cipher, unsigned char* key){
	if (cipher == NULL || key == NULL) return -1;
	
	cipher->key = key;
	cipher->len = (unsigned int)strlen((char*)key);

	return 0;
}

int vigerene_encode(vigenere_cipher_t* cipher, unsigned char string[]){

    // No aceptamos cadenas vacías ni NULLs.
    if (string == NULL) return -1;
	unsigned int n = (unsigned int)strlen((char*)string);
	unsigned int m = (unsigned int)strlen((char*)cipher->key);

    for (int i = 0; i < n; i++) printf("%d|",string[i]);
    printf("\n");
    for (int i = 0; i < m; i++) printf("%d|",cipher->key[i]);
    printf("\n");

    char buf[n];

    int max = m > n ? m : n;
    for (int i = 0; i < n; i++){
        unsigned char suma = string[i % n] + cipher->key[i % m];
        printf("value[i & n] + key[i & m]: %d \n",suma);
        buf[i] = suma % 256;
    }

    for (int i = 0; i < n; i++) printf("%d|",buf[i]);
    printf("\n");

    return 0;
}

int main(int argc, char* argv[]){

    char key[] = "SecureKey";
	int r = 0; 

    for (int j = 1; j < argc; j++){
 
        vigenere_cipher_t cipher;
        r = vigenere_cipher_init(&cipher,key);
        
		printf("Pasando: %s\n",argv[j]);
        r = vigenere_encode(&cipher,argv[j]);
    }

	return r;
}
