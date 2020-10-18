// Copyright [2020]<Jonathan David Rosenblatt>
#include "common_file_reader.h"

#include <stdio.h>

int read_from_file_to_buf(char buf[], unsigned int msgLen, FILE* fp) {
  unsigned int porLeer = msgLen;
  unsigned int leidos = 0;
  while (!feof(fp) && porLeer != 0) {
    leidos += fread(buf + leidos, 1, msgLen, stdin);
    porLeer -= leidos;
    buf[leidos] = 0;
  }
  return leidos;
/*  int leidos = 0;
  while (leidos < msgLen){
    if (fgets(buf,1,fp) == NULL){
      buf[leidos] = 0;
      return 0;
    }
	leidos++;
  }
  buf[leidos] = 0;
  return leidos;
*/}
