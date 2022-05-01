#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


char* SHA256(char* input,char* hash);

//step 1
void textToBinary(char* input, char* output);
void append_f (char *input);


//step2
char* hexToBin(char* string, char* bits);
char* hToB(char oneHex);

//step4
char*rounds(char *fullPaddedMessage);


//step5
int createMessageScheduling(char* bitsString, uint32_t bitArray[64]);
void makeArrayOfBitStrings(char* bitsString, char[64][34] );
void makeArrayOfBitInts (char[64][34],uint32_t bitArray[64]);
uint32_t bitsTo32Ints(char *);
void add48Ints(uint32_t bitArray[64]);
void modify(uint32_t bitArray[64]);

//step6
void step6(uint32_t w[64]);

//step7
void step7();
char * binaryRep (uint32_t  n, char * binary);
char * binaryRep64 (uint64_t  n, char * binary);

//step8
char* BToh(char* input, char * output);
char* finalHash(char * input);
bool equivalent(char * Str1, char * Str2);
bool equivalent1(char * dest, char * neww);

//helper functions
uint32_t right_rotate(uint32_t num, int n);
int xor(uint32_t  a, uint32_t  b);
uint32_t right_shift(uint32_t num, int n);
void cpy(char* ,char* );
int len(char*);
void cat(char* dest, char*new);
char* catc(char* dest, char new);


#endif
