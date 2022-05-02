#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//The top function the runs all the steps:
char* SHA256(char* input,char* hash);

//step 1
void textToBinary(char* input, char* output); // converts text to binary
void append_f (char *input); //appends 1 and 0 to make input a multipule of 512


//step2
char* hexToBin(char* string, char* bits); // converts hexadecime to Binary
char* hToB(char oneHex); //helper to hexadecime to Binary

//step4
char*rounds(char *fullPaddedMessage); // calls the rest of the steps using chuncks of 512 bits


//step5
int createMessageScheduling(char* bitsString, uint32_t bitArray[64]); //main function for step 5 which calls all the subfunctions of step 5
void makeArrayOfBitStrings(char* bitsString, char[64][34] ); //makes an array of bits in string form
void makeArrayOfBitInts (char[64][34],uint32_t bitArray[64]); //converts the array of bits in string from to an array of 32 bit integers
uint32_t bitsTo32Ints(char *); //converts binary to int32
void add48Ints(uint32_t bitArray[64]);  // appends 48 zeroed elements array if integers
void modify(uint32_t bitArray[64]); // modifies the zeroed bit elements

//step6
void step6(uint32_t w[64]); // perfomrs the compression function

//step7
void step7(); //adds h values and varibles
char * binaryRep (uint32_t  n, char * binary); //from int32 to binary 
char * binaryRep64 (uint64_t  n, char * binary);//from int64 to binary 

//step8
char* BToh(char* input, char * output); //from binary to hex
char* finalHash(char * input); // outputs the final hash by concatinating the h values
bool equivalent(char * Str1, char * Str2); // checks for equvelnce of two strings
bool equivalent1(char * dest, char * neww);// checks for equvelnce of two strings

//helper functions
uint32_t rightRotate(uint32_t num, int n);
uint32_t right_rotate(uint32_t num, int n); //rotates bits 
int xor(uint32_t  a, uint32_t  b); // xor two numbers
uint32_t right_shift(uint32_t num, int n); //right shifts bits
void cpy(char* ,char* ); // copys a string from one function to another
int len(char*); // gets the length of a string 
void cat(char* dest, char*new); // concatinats two strings
char* catc(char* dest, char new);// concatinats a string with a character


#endif
