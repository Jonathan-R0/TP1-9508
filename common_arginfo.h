#ifndef ARGINFO_H_ 
#define ARGINFO_H_

#define SIZE_OF_STRINGS 256

typedef struct arginfo{
	char method[SIZE_OF_STRINGS];
	char key[SIZE_OF_STRINGS];
	char port[SIZE_OF_STRINGS];
	char ip[SIZE_OF_STRINGS];
}arginfo_t;

int arginfo_init(arginfo_t* info, int argc, char* argv[]);

#endif
