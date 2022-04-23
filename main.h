#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

char* SHA256(char* input,char* hash);

//step 1
char* textToBinary(char* string,char* hash);
char* append_f (char *input);


//step2
char* hexToBin(char* string, char* bits);
char* hToB(char oneHex);

//step5
void makeArrayOfBitStrings(char* bitsString, char[16][34] );
int createMessageScheduling(char* bitsString, uint32_t* bitArray);
uint32_t sToB(char *);


//helper functions
void cpy(char* ,char* );
int len(char*);
void cat(char* dest, char*new);
char* catc(char* dest, char new);


#endif
