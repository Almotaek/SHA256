#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "main.h"

bool equivalent(char * dest, char * new);

int main(){
  //Step1 Test
   char input[512] = "hello world";
   char output [512] = "";
   char expected[512] = "01101000011001010110110001101100011011110010000001110111011011110111001001101100011001001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
   textToBinary(input,output);
   append_f(output);
   printf("%d\n", len(output));
   printf("Actual Result: %s\n",output);
   printf("Expected Result: %s\n",expected);
   printf("Success (1/0)? %d\n",equivalent(output,expected));
   return 0;

}











//bool equivalent(char * Str1, char * Str2){
//   int result, i;
//   i = 0;
//   while(Str1[i] == Str2[i] && Str1[i] == '\0'){
//       i++;
//
//   if(Str1[i] != Str2[i])
//   {
//       return false;
//   }
//   }
//   return true;
//}

