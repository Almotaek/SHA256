#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "main.h"


int main() {
	char input[511] = "hello world"; //Input
	char hash[513] = ""; //Hash
	SHA256(input,hash); // Calling the top function
	printf("Hash: %s\n",hash); 
    return 0;
 }

