#include "main.h"


char* SHA256(char* input,char* hash) {
	#pragma HLS INTERFACe s_axilite port=return bundle=CRTLS
	#pragma HLS INTERFACe s_axilite port=input bundle=CRTLS
	#pragma HLS INTERFACe s_axilite port=hash bundle=CRTLS


	//STEP 1:
	textToBinary(input,hash);

//	append_f(input);



	//STEP2:

    //initlizing hash values 0..7
    char h0[12] = "";
    char h1[12] = "";
    char h2[12] = "";
    char h3[12] = "";
    char h4[12] = "";
    char h5[12] = "";
    char h6[12] = "";
    char h7[12] = "";


    //the fractions of the sqaure roots of the 1st 8 prime numbers.
    char* H0 = "0x6a09e667";
    char* H1 = "0xbb67ae85";
    char* H2 = "0x3c6ef372";
    char* H3 = "0xa54ff53a";
    char* H4 = "0x510e527f";
    char* H5 = "0x9b05688c";
    char* H6 = "0x1f83d9ab";
    char* H7 = "0x5be0cd19";

    //setting the hash values h0 through h7 to be equal to the binary from of the fractions of the sqaure roots of the 1st 8 prime numbers.
    hexToBin(H0,h0);
    hexToBin(H1,h1);
    hexToBin(H2,h2);
    hexToBin(H3,h3);
    hexToBin(H4,h4);
    hexToBin(H4,h0);
    hexToBin(H5,h5);
    hexToBin(H6,h6);
    hexToBin(H7,h7);

    //end of h value creation

	//STEP 3:

	//creating k-constants
    //initlizing hash values 0..63
//    char k0[12] = "";
//    char k1[12] = "";
//    char k2[12] = "";
//    char k3[12] = "";
//    char k4[12] = "";
//    char k5[12] = "";
//    char k6[12] = "";
//    char k7[12] = "";
//    char k8[12] = "";
//    char k9[12] = "";
//    char k10[12] = "";
//    char k11[12] = "";
//    char k12[12] = "";
//    char k13[12] = "";
//    char k14[12] = "";
//    char k15[12] = "";
//    char k16[12] = "";
//    char k17[12] = "";
//    char k18[12] = "";
//    char k19[12] = "";
//    char k20[12] = "";
//    char k21[12] = "";
//    char k22[12] = "";
//    char k23[12] = "";
//    char k24[12] = "";
//    char k25[12] = "";
//    char k26[12] = "";
//    char k27[12] = "";
//    char k28[12] = "";
//    char k29[12] = "";
//    char k30[12] = "";
//    char k31[12] = "";
//    char k32[12] = "";
//    char k33[12] = "";
//    char k34[12] = "";
//    char k35[12] = "";
//    char k36[12] = "";
//    char k37[12] = "";
//    char k38[12] = "";
//    char k39[12] = "";
//    char k40[12] = "";
//    char k41[12] = "";
//    char k42[12] = "";
//    char k43[12] = "";
//    char k44[12] = "";
//    char k45[12] = "";
//    char k46[12] = "";
//    char k47[12] = "";
//    char k48[12] = "";
//    char k49[12] = "";
//    char k50[12] = "";
//    char k51[12] = "";
//    char k52[12] = "";
//    char k53[12] = "";
//    char k54[12] = "";
//    char k55[12] = "";
//    char k56[12] = "";
//    char k57[12] = "";
//    char k58[12] = "";
//    char k59[12] = "";
//    char k60[12] = "";
//    char k61[12] = "";
//    char k62[12] = "";
//    char k63[12] = "";
    //the fractions of the sqaure roots of the 1st 64 prime numbers.
//    char* K0 = "0x428a2f98";
//    char* K1 = "0x71374491";
//    char* K2 = "0xb5c0fbcf";
//    char* K3 = "0xe9b5dba5";
//    char* K4 = "0x3956c25b";
//    char* K5 = "0x59f111f1";
//    char* K6 = "0x923f82a4";
//    char* K7 = "0xab1c5ed5";
//    char* K8 = "0xd807aa98";
//    char* K9 = "0x12835b01";
//    char* K10 = "0x243185be";
//    char* K11 = "0x550c7dc3";
//    char* K12 = "0x72be5d74";
//    char* K13 = "0x80deb1fe";
//    char* K14 = "0x9bdc06a7";
//    char* K15 = "0xc19bf174";
//    char* K16 = "0xe49b69c1";
//    char* K17 = "0xefbe4786";
//    char* K18 = "0x0fc19dc6";
//    char* K19 = "0x240ca1cc";
//    char* K20 = "0x2de92c6f";
//    char* K21 = "0x4a7484aa";
//    char* K22 = "0x5cb0a9dc";
//    char* K23 = "0x76f988da";
//    char* K24 = "0x983e5152";
//    char* K25 = "0xa831c66d";
//    char* K26 = "0xb00327c8";
//    char* K27 = "0xbf597fc7";
//    char* K28 = "0xc6e00bf3";
//    char* K29 = "0xd5a79147";
//    char* K30 = "0x06ca6351";
//    char* K31 = "0x14292967";
//    char* K32 = "0x27b70a85";
//    char* K33 = "0x2e1b2138";
//    char* K34 = "0x4d2c6dfc";
//    char* K35 = "0x53380d13";
//    char* K36 = "0x650a7354";
//    char* K37 = "0x766a0abb";
//    char* K38 = "0x81c2c92e";
//    char* K39 = "0x92722c85";
//    char* K40 = "0xa2bfe8a1";
//    char* K41 = "0xa81a664b";
//    char* K42 = "0xc24b8b70";
//    char* K43 = "0xc76c51a3";
//    char* K44 = "0xd192e819";
//    char* K45 = "0xd6990624";
//    char* K46 = "0xf40e3585";
//    char* K47 = "0x106aa0707";
//    char* K48 = "0x19a4c116";
//    char* K49 = "0x1e376c08";
//    char* K50 = "0x2748774c";
//    char* K51 = "0x34b0bcb5";
//    char* K52 = "0x391c0cb3";
//    char* K53 = "0x4ed8aa4a";
//    char* K54 = "0x5b9cca4f";
//    char* K55 = "0x682e6ff3";
//    char* K56 = "0x748f82ee";
//    char* K57 = "0x78a5636f";
//    char* K58 = "0x84c87814";
//    char* K59 = "0x8cc70208";
//    char* K60 = "0x90befffa";
//    char* K61 = "0xa4506ceb";
//    char* K62 = "0xbef9a3f";
//    char* K63 = "0xbef9a3f";//CHANGE!


    //setting the hash values h0 through h63 to be equal to the binary from of the fractions of the sqaure roots of the 1st 64 prime numbers.
//    hexToBin(K0,k0);
//    hexToBin(K1,k1);
//    hexToBin(K2,k2);
//    hexToBin(K3,k3);
//    hexToBin(K4,k4);
//    hexToBin(K5,k5);
//    hexToBin(K6,k6);
//    hexToBin(K7,k7);
//    hexToBin(K8,k8);
//    hexToBin(K9,k9);
//    hexToBin(K10,k10);
//    hexToBin(K11,k11);
//    hexToBin(K12,k12);
//    hexToBin(K13,k13);
//    hexToBin(K14,k14);
//    hexToBin(K15,k15);
//    hexToBin(K16,k16);
//    hexToBin(K17,k17);
//    hexToBin(K18,k18);
//    hexToBin(K19,k19);
//    hexToBin(K20,k20);
//    hexToBin(K21,k21);
//    hexToBin(K22,k22);
//    hexToBin(K23,k23);
//    hexToBin(K24,k24);
//    hexToBin(K25,k25);
//    hexToBin(K26,k26);
//    hexToBin(K27,k27);
//    hexToBin(K28,k28);
//    hexToBin(K29,k29);
//    hexToBin(K30,k30);
//    hexToBin(K31,k31);
//    hexToBin(K32,k32);
//    hexToBin(K33,k33);
//    hexToBin(K44,k44);
//    hexToBin(K45,k45);
//    hexToBin(K46,k46);
//    hexToBin(K47,k47);
//    hexToBin(K48,k48);
//    hexToBin(K49,k49);
//    hexToBin(K50,k50);
//    hexToBin(K51,k51);
//    hexToBin(K52,k52);
//    hexToBin(K53,k53);
//    hexToBin(K54,k54);
//    hexToBin(K55,k55);
//    hexToBin(K56,k56);
//    hexToBin(K57,k57);
//    hexToBin(K58,k58);
//    hexToBin(K59,k59);
//    hexToBin(K60,k60);
//    hexToBin(K61,k61);
//    hexToBin(K62,k62);
//    hexToBin(K63,k63);

    //end of k value creation






    //step5







    //hash/test results:
    cpy(hash,h0);
	return hash;


 }


//STEP 1 Functions:

void textToBinary(){
	int i;

   char *string = "String to Binary In C";
   for(i=0;i<8*strlen(string);i++)
	 printf("%d",0 != (string[i/8] & 1 << (~i&7)));

	 printf("\n");
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


char* hexToBin(char* string, char* bits){
    int i =0;
    while(string[i]!='\0'){ //loopes through the hex string
        if(i>1){
            cat(bits,hToB(string[i])); //concatnates the new binary string
        }
        i++;
    }

    return bits;
}


//converts a hex digit to a binary string
char* hToB(char oneHex){
    switch (oneHex){
        case '0':
        return "0000";
        case '1':
        return "0001";
        case '2':
        return "0010";
        case '3':
        return "0011";
        case '4':
        return "0100";
        case '5':
        return "0101";
        case '6':
        return "0110";
        case '7':
        return "0111";
        case '8':
        return "1000";
        case '9':
        return "1001";
        case 'A':
        return "1010";
        case 'B':
        return "1011";
        case 'C':
        return "1100";
        case 'D':
        return "1101";
        case 'E':
        return "1110";
        case 'F':
        return "1111";
        case 'a':
        return "1010";
        case 'b':
        return "1011";
        case 'c':
        return "1100";
        case 'd':
        return "1101";
        case 'e':
        return "1110";
        case 'f':
        return "1111";
        default:
        return "ERROR";
    }
}

//step 5

int createMessageScheduling(char* bitsString, uint32_t* bitArray){
	  char stringBitArray[64][34];
	  makeArrayOfBitStrings (bitsString, stringBitArray);
      //call a function that populates the bitArray with the values of int value of stringBitArray using bitsTo32Ints
	  makeArrayOfBitInts(stringBitArray,bitArray);
	  //adding 48 more words (i.e. 48 more uint32_t elements)
	  add48Ints(bitArray);
      //now, bitArray can be used to preform the operations of step 5.
      modify(bitArray);
	  return 0;
}

void makeArrayOfBitInts (char stringBitArray[64][34],uint32_t * bitArray){
    int i = 0;
    for(i=0; i<32; i++){
        // printf ("%s\n", stringBitArray[i]);
        bitArray[i] = bitsTo32Ints(stringBitArray[i]);
    }
}

void makeArrayOfBitStrings (char *bitsString, char stringBitArray[64][34])
{
  int i = 0;
  int c = 0;
  int index = 0;
  char currentInt[99] = "";
  while (bitsString[i] != '\0')
    {
     //  printf ("%d\n", i);
    //   printf ("%c\n", bitsString[i]);
      catc (currentInt, bitsString[i]);
      //printf ("%s\n", currentInt);
      if (c == 31)
	{
	  currentInt[c+1] = '\0';
	  stringBitArray[index][c+1] = '\0';
	  cpy (stringBitArray[index], currentInt);
	  //currentInt[c] = '\0';
	  c = 0;
	  currentInt[0] = '\0';
	  index++;
	}else{
	    c++;
	}

	  i++;


    }
}

void add48Ints(uint32_t * bitArray){
    int i = 33;
    for(i = 33; i<64; i ++){
        bitArray[i] = 0;
    }
}

void modify(uint32_t* ints){
    int i = 0;
    for(i=16; i<64; i++){
        uint32_t s0  = xor(xor(right_rotate(ints[i-15], 7), right_rotate(ints[i-15], 8)),  right_shift(ints[i-15], 8));
        uint32_t s1  = xor(xor(right_rotate(ints[i-2], 17), right_rotate(ints[i-2], 19)),  right_shift(ints[i-2], 10));
        ints[i] = ints[i-16] + s0 + ints[i-7] + s1;
    }
}


//string to int32_t
uint32_t bitsTo32Ints(char * string){
	uint32_t x = 0;
    int i =0;
    uint32_t t = 1;
    uint32_t total = 0;
    for(i=31; i>=0; i--){
        // printf("%d",i);
        int oz = string[i]-48;
        // printf("%d\n",oz);
        if(oz==1){
            total  = total + t;
        }
        t=t*2;
    }
    return total;
}


//helper functions

uint32_t right_shift(uint32_t num, int n) {
  return num >> n;
}
uint32_t right_rotate(uint32_t num, int n) {
  return (num >> n) | (num << (32 - n));
}

int xor(uint32_t  a, uint32_t  b){
    return a ^ b;
}

char* catc(char* dest, char new){
	int i = 0;
	int j =0;
	i = len(dest);
	dest[i] = new;
	dest[i+1] = '\0';
	return dest;
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


void cat(char* dest, char*new){
	int i = 0;
	int j =0;
	i = len(dest);
	while(new[j] != '\0'){
		dest[i] = new[j];
		i++;
		j++;
	}
}




