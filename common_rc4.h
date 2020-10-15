#ifndef RC4_H_
#define RC4_H_

/*
 * Las variables 'S', 'a' y 'b' existen para que el struct pueda generar el
 * valor con el que se hace el XOR al mensaje entrante. Estos deben existir en
 * el struct ya que la encriptación correcta cada mensaje depende de que se
 * guarde el estado de estas variables de iteraciones anteriores.
 */
typedef struct rc4_cipher {
  unsigned char S[256];
  unsigned char* key;
  unsigned int a;
  unsigned int b;
} rc4_cipher_t;

/*
 * Swappea los elementos de la posición "coef1" y "coef2" dentro del arreglo
 * recibido. Precondiciones: s != NULL && coef1,coef2 < strlen(s)
 * Postcondiciones: swappea los elementos, si el arreglo ingresado es NULL no
 * hace nada.
 */
void swap(unsigned char* s, unsigned int coef1, unsigned int coef2);

/*
 * Devuelve un char cuyo valor numérico está generado en función del estado del
 * cipher que ingrese. Precondiciones: cipher != NULL && cipher inicializado.
 * Postcondiciones: devuelve el char generado.
 */
unsigned char randChar(rc4_cipher_t* cipher);

/*
 * Inicializa el cipher dada la key ingresada.
 * Precondiciones: cipher != NULL && key != NULL
 * Postcondiciones: deja el cipher inicializado. Devuevle -1 en caso de error, 0
 * de lo contrario.
 */
int rc4_cipher_init(rc4_cipher_t* cipher, unsigned char* key);

/*
 * Codifica el mensaje ingresado en función el cipher dado.
 * Precondiciones: cipher != NULL && ciper inicializado && string != NULL.
 * Postcondiciones: deja el mensaje codificado en el array ingresado. Devuelve
 * -1 en caso de error, 0 de lo contrario
 */
int rc4_encode(rc4_cipher_t* cipher, unsigned char string[]);

/*
 * Decodifica el mensaje ingresado en función el cipher dado.
 * Precondiciones: cipher != NULL && cipher inicializado && string != NULL.
 * Postcondiciones: deja el mensaje decodificado en el array ingresado. Devuelve
 * -1 en caso de error, 0 de lo contrario.
 */
int rc4_decode(rc4_cipher_t* cipher, unsigned char string[], unsigned int len);

#endif
