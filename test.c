#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "main.h"


int main() {
	char input[511] = "hello world";
	char hash[513] = "";
	SHA256(input,hash);
	printf("Hash: %s\n",hash);
    return 0;
 }

