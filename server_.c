#include <stdio.h>
#include "arginfo.h"

#define ERR_ARG_NRO "Error, argumento inválido.\n"

int main(int argc, char *argv[]){

	if (argc != 4){
		fprintf(stderr,ERR_ARG_NRO);
		return 1;
	}	

    arginfo_t arginfo;
	if (!arginfo_init(&arginfo,argc,argv)) return 1;
	printf("Bien papá\nmethod: %s\nkey: %s\n",arginfo.method,arginfo.key);
	return 0;

}
