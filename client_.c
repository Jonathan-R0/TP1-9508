#include <stdio.h>
#include <unistd.h> 
#include "common_arginfo.h"

#define BYTES_A_LEER 64
#define ERR_ARG_NRO "Error, argumento inválido.\n"

void do_stuff_with_stdin(arginfo_t* info){
	
	char buf[BYTES_A_LEER];
	size_t leidos;
	size_t porLeer = BYTES_A_LEER;
	while(!feof(stdin)){
		leidos = fread(buf,1,porLeer,stdin); 
		buf[leidos] = '\0';
		printf("%s - %ld\n",buf,leidos);
	}
}

int main(int argc, char *argv[]){

	if (argc != 5){
		fprintf(stderr,ERR_ARG_NRO);
		return 1;
	}	

	for (int i = 0; i < argc; i++) printf("%d - %s\n",i,argv[i]);

    arginfo_t arginfo;
	if (!arginfo_init(&arginfo,argc,argv)) return 1;
	printf("Funciona con:\nmethod: %s\nkey: %s\nport: %s\nip: %s\n",arginfo.method,arginfo.key,arginfo.port,arginfo.ip);
	do_stuff_with_stdin(&arginfo);

	return 0;
}
