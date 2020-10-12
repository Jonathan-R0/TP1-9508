#ifndef CESAR_H_
#define CESAR_H_

typedef struct cesar_cipher{
    unsigned int shift;
}cesar_cipher_t;

int cesar_cipher_init(cesar_cipher_t* cipher, unsigned int key);

int cesar_encode(cesar_cipher_t* cipher, unsigned char string[]);

int cesar_decode(cesar_cipher_t* cipher, unsigned char string[], unsigned int msgLen);

int cesar_shift_bytes(int shift, unsigned char string[], unsigned int msgLen);

#endif

