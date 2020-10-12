#include <stdio.h>
#include "common_arginfo.h"

#define ERR_ARG_NRO "Error, argumento inválido.\n"

int main(int argc, char *argv[]){

	if (argc != 4){
		fprintf(stderr,ERR_ARG_NRO);
		return 1;
	}	

    arginfo_t arginfo;
	if (!arginfo_init(&arginfo,argc,argv)) return 1;
	printf("Funciona con:\nmethod: %s\nkey: %s\nport: %s\nip: %s\n",arginfo.method,arginfo.key,arginfo.port,arginfo.ip);
	return 0;

}
