#include "main.h"


char* SHA256(char* input,char* hash) {
	#pragma HLS INTERFACe s_axilite port=return bundle=CRTLS
	#pragma HLS INTERFACe s_axilite port=input bundle=CRTLS
	#pragma HLS INTERFACe s_axilite port=hash bundle=CRTLS


	//STEP 1:
	textToBinary(input,hash);

//	append_f(input);



	//STEP2:
//    //initlizing hash values 0..7
//    char h0[40] = "";
//    char h1[40] = "";
//    char h2[40] = "";
//    char h3[40] = "";
//    char h4[40] = "";
//    char h5[40] = "";
//    char h6[40] = "";
//    char h7[40] = "";
//
//
//    //the fractions of the sqaure roots of the 1st 8 prime numbers.
//    char* H0 = "0x6a09e667";
//    char* H1 = "0xbb67ae85";
//    char* H2 = "0x3c6ef372";
//    char* H3 = "0xa54ff53a";
//    char* H4 = "0x510e527f";
//    char* H5 = "0x9b05688c";
//    char* H6 = "0x1f83d9ab";
//    char* H7 = "0x5be0cd19";
//
//    //setting the hash values h0 through h7 to be equal to the binary from of the fractions of the sqaure roots of the 1st 8 prime numbers.
//    hexToBin(H0,h0);
//    hexToBin(H1,h1);
//    hexToBin(H2,h2);
//    hexToBin(H3,h3);
//    hexToBin(H4,h4);
//    hexToBin(H4,h0);
//    hexToBin(H5,h5);
//    hexToBin(H6,h6);
//    hexToBin(H7,h7);
//
//    //end of inilization

	//STEP 3:




	return input;


 }



char* textToBinary(char* string,char* hash){
	char* binary = "0010100101010110001010101010101011";
	cpy(hash,binary);
    return hash;
 }

void cpy(char* dest, char* source){
	int i = 0;
	while(source[i]!='\0'){
		dest[i] = source[i];
		i = i + 1;
	}
}

int len(char* txt){
	int i = 0;
	while(txt[i]!='\0'){
		i++;
	}
	return i;
}

//char* append_f (char *input)
//{
//  //length of the original input string
//  int a = len(input);
//  // the remainder after dividing the length of the string by 512
//  int rem_512 = a % 512;
//  const int new_length = a + (512 - rem_512);
//
//  //this is final hash that would be produced
//  char message_block [new_length]; // you cannot do this in HLS
//
//
//
//  //copying the initial contents of the input string
//  int i = 0;
//  for (i=0; i < a; i++){
//      message_block[i] = input[i];
//  }
//
//  message_block[a] = '1';
//
//
//  int j = 0;
//  for (j = a+1; j < new_length-64; j++)
//    {
//      message_block[j] = '0';
//    }
//
//
////  printf ("%s \n", message_block);
//  cpy(input,message_block);
//  return input;
//
//
//}


//char* hexToBin(char* string, char* bits){
//    int i =0;
//    while(string[i]!='\0'){ //loopes through the hex string
//        if(i>1){
//            strcat(bits,hToB(string[i])); //concatnates the new binary string
//        }
//        i++;
//    }
//
//    return bits;
//}

//
////converts a hex digit to a binary string
//char* hToB(char oneHex){
//    switch (oneHex){
//        case '0':
//        return "0000";
//        case '1':
//        return "0001";
//        case '2':
//        return "0010";
//        case '3':
//        return "0011";
//        case '4':
//        return "0100";
//        case '5':
//        return "0101";
//        case '6':
//        return "0110";
//        case '7':
//        return "0111";
//        case '8':
//        return "1000";
//        case '9':
//        return "1001";
//        case 'A':
//        return "1010";
//        case 'B':
//        return "1011";
//        case 'C':
//        return "1100";
//        case 'D':
//        return "1101";
//        case 'E':
//        return "1110";
//        case 'F':
//        return "1111";
//        case 'a':
//        return "1010";
//        case 'b':
//        return "1011";
//        case 'c':
//        return "1100";
//        case 'd':
//        return "1101";
//        case 'e':
//        return "1110";
//        case 'f':
//        return "1111";
//        default:
//        return "ERROR";
//    }
//}




