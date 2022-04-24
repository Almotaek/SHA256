#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

char* SHA256(char* input,char* hash);

//step 1
void textToBinary(char* string,char* hash);
char* append_f (char *input);


//step2
char* hexToBin(char* string, char* bits);
char* hToB(char oneHex);

//step5
int createMessageScheduling(char* bitsString, uint32_t* bitArray);
void makeArrayOfBitStrings(char* bitsString, char[64][34] );
void makeArrayOfBitInts (char[64][34],uint32_t * bitArray);
uint32_t bitsTo32Ints(char *);
void add48Ints(uint32_t* bitArray);
void modify(uint32_t* ints);



//helper functions
uint32_t right_rotate(uint32_t num, int n);
int xor(uint32_t  a, uint32_t  b);
uint32_t right_shift(uint32_t num, int n);
void cpy(char* ,char* );
int len(char*);
void cat(char* dest, char*new);
char* catc(char* dest, char new);


#endif
