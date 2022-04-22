#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

//char* SHA256(char* inputPlain,char* hash);
//char* textToBinary(char* string,char* hash);

int main() {
	char* input = "Hello World";
	char hash[512] = "";
    SHA256(input,hash);
    printf("Result: %s\n",hash);
    return 0;
 }

