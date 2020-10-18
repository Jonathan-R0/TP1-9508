// Copyright [2020]<Jonathan David Rosenblatt>
#ifndef COMMON_FILE_READER_H_
#define COMMON_FILE_READER_H_

#include <stdio.h>

int read_from_file_to_buf(char buf[], unsigned int msgLen, FILE* fp);

#endif  // COMMON_FILE_READER_H_
