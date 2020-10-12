#include <string.h>
#include <stdio.h>
#include <getopt.h>
#include "common_arginfo.h"

#define SIZE_OF_STRINGS 256
#define ERR_OVERFLOW "Error, el método de encriptación y/o llave son demasiado largos.\n"
#define ERR_INV_TYPE "Error, opcion pasada por argumento no válida.\n"
#define METODO_DE_ENCRIPTACION "method="
#define LLAVE_DE_ENCRIPTACION "key="

void getPortAndIp(arginfo_t* info, int argc, char* argv[]){
	if (argc == 4){
		strncpy(info->port,argv[3],sizeof(argv[3]));
		*(info->ip) = '\0';
	} else {
		strncpy(info->port,argv[4],sizeof(argv[4]));
		strncpy(info->ip,argv[3],sizeof(argv[3]));
	}
}

int arginfo_init(arginfo_t* info, int argc, char* argv[]){

    int opt; int hayLlave = 0; int hayMetodo = 0;
    const struct option validArgs[] =
        {{.name = METODO_DE_ENCRIPTACION, .has_arg = required_argument, .val = 'm'},
         {.name = LLAVE_DE_ENCRIPTACION, .has_arg = required_argument, .val = 'k'},{}};

    while ((opt = getopt_long(argc, argv, "mk", validArgs, NULL)) != -1){
        if (sizeof(optarg) >= SIZE_OF_STRINGS){
            fprintf(stderr,ERR_OVERFLOW);
            return 0;
        }
        switch (opt){
            case('m'):
                strncpy(info->method,optarg,sizeof(optarg));
                hayMetodo++;
                continue;
            case('k'):
                strncpy(info->key,optarg,sizeof(optarg));
                hayLlave++;
                continue;
            default:
                fprintf(stderr,ERR_INV_TYPE);
                return 0;
        }
    }

	getPortAndIp(info,argc,argv);	
	// Esperamos que tenga llave y método.
    return (hayLlave && hayMetodo);
}
