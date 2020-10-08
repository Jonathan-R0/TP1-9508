#ifndef RC4_H_
#define RC4_H_ 

typedef struct rc4_cipher{
    unsigned char S[256];
    unsigned char* key;
    unsigned int a;
    unsigned int b;
}rc4_cipher_t;

void swap(unsigned char *s, unsigned int coef1, unsigned int coef2);

unsigned char randInt(rc4_cipher_t* cipher);

int rc4_cipher_init(rc4_cipher_t* cipher, unsigned char* key);

int rc4_encode(rc4_cipher_t* cipher, unsigned char string[]);

#endif
