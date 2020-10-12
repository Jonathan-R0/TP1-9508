#ifndef VIGENERE_H_
#define VIGENERE_H_

typedef struct vigenere_cipher{
    unsigned char* key;
	unsigned int lastKeyIndex;
}vigenere_cipher_t;

int vigenere_cipher_init(vigenere_cipher_t* cipher, unsigned char* key);

int vigenere_cipher_shift_bytes(vigenere_cipher_t* cipher, short estoyCifrando, unsigned char string[], unsigned int msgLen);

int vigenere_encode(vigenere_cipher_t* cipher, unsigned char string[]);

int vigenere_decode(vigenere_cipher_t* cipher, unsigned char string[], unsigned int msgLen);

#endif
