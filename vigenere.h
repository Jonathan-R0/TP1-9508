#ifndef VIGENERE_H_
#define VIGENERE_H_

typedef struct vigenere_cipher{
    unsigned char* key;
}vigenere_cipher_t;

int vigenere_cipher_init(vigenere_cipher_t* cipher, unsigned char* key);

int vigenere_cipher_shift_bytes(unsigned char* key, unsigned char string[], short estoyCifrando);

int vigenere_encode(vigenere_cipher_t* cipher, unsigned char string[]);

int vigenere_decode(vigenere_cipher_t* cipher, unsigned char string[]);

#endif
