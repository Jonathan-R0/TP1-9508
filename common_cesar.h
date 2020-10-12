#ifndef CESAR_H_
#define CESAR_H_

typedef struct cesar_cipher{
    unsigned int shift;
}cesar_cipher_t;

/*
 * Inicializa el cipher recibido con la key, es decir, con el valor númerico que representa la cantidad
 * de bytes a shiftear cada char del mensaje.
 * Precondiciones: cipher != NULL.
 * Postcondiciones: deja el cipher inicializado. Devuelve -1 en caso de error, 0 de lo contrario.
 */
int cesar_cipher_init(cesar_cipher_t* cipher, unsigned int key);

/*
 * Dado un mensaje se codifica en función del incremento de caracteres indicado por el cipher. 
 * Precondición: string != NULL && cipher inicializado && cipher != NULL.
 * Postcondiciones: deja el mensaje cifrado en el mismo array que ingresa. Devuelve -1 en
 * caso de error, 0 de lo contrario. 
 */
int cesar_encode(cesar_cipher_t* cipher, unsigned char string[]);

/*
 * Dado un mensaje se decodifica en función del decremento de caracteres indicado por el cipher. 
 * Precondición: string != NULL && cipher inicializado && cipher != NULL.
 * Postcondiciones: deja el mensaje descifrado en el mismo array que ingresa. Devuelve -1 en
 * caso de error, 0 de lo contrario. 
 */
int cesar_decode(cesar_cipher_t* cipher, unsigned char string[], unsigned int msgLen);

/*
 * Dado un mensaje se codifica o decodifica, en función del incremento o decremento a computar en los
 * caracteres. 
 * Precondición: string != NULL.
 * Postcondiciones: deja el mensaje cifrado o descifrado en el mismo array que ingresa. Devuelve -1 en
 * caso de error, 0 de lo contrario. 
 */
int cesar_shift_bytes(int shift, unsigned char string[], unsigned int msgLen);

#endif

