#include "main.h"

//creating hash values 0..7
char h0[33] = "";
char h1[33] = "";
char h2[33] = "";
char h3[33] = "";
char h4[33] = "";
char h5[33] = "";
char h6[33] = "";
char h7[33] = "";

//creating k-constants
//initializing hash values 0..63
char k[64][33] = {
  ""
};
char K[64][12] = {
  "0x428a2f98",
  "0x71374491",
  "0xb5c0fbcf",
  "0xe9b5dba5",
  "0x3956c25b",
  "0x59f111f1",
  "0x923f82a4",
  "0xab1c5ed5",
  "0xd807aa98",
  "0x12835b01",
  "0x243185be",
  "0x550c7dc3",
  "0x72be5d74",
  "0x80deb1fe",
  "0x9bdc06a7",
  "0xc19bf174",
  "0xe49b69c1",
  "0xefbe4786",
  "0x0fc19dc6",
  "0x240ca1cc",
  "0x2de92c6f",
  "0x4a7484aa",
  "0x5cb0a9dc",
  "0x76f988da",
  "0x983e5152",
  "0xa831c66d",
  "0xb00327c8",
  "0xbf597fc7",
  "0xc6e00bf3",
  "0xd5a79147",
  "0x06ca6351",
  "0x14292967",
  "0x27b70a85",
  "0x2e1b2138",
  "0x4d2c6dfc",
  "0x53380d13",
  "0x650a7354",
  "0x766a0abb",
  "0x81c2c92e",
  "0x92722c85",
  "0xa2bfe8a1",
  "0xa81a664b",
  "0xc24b8b70",
  "0xc76c51a3",
  "0xd192e819",
  "0xd6990624",
  "0xf40e3585",
  "0x106aa070",
  "0x19a4c116",
  "0x1e376c08",
  "0x2748774c",
  "0x34b0bcb5",
  "0x391c0cb3",
  "0x4ed8aa4a",
  "0x5b9cca4f",
  "0x682e6ff3",
  "0x748f82ee",
  "0x78a5636f",
  "0x84c87814",
  "0x8cc70208",
  "0x90befffa",
  "0xa4506ceb",
  "0xbef9a3f",
  "0xc67178f2"
};

//initializing variables
uint32_t a;
uint32_t b;
uint32_t c;
uint32_t d;
uint32_t e;
uint32_t f;
uint32_t g;
uint32_t h;

char * SHA256(char * input, char * hash) {
  //HLS COMMNANDS   :
  #pragma HLS INTERFACe s_axilite port = return bundle = CRTLS
  #pragma HLS INTERFACe s_axilite port = input bundle = CRTLS
  #pragma HLS INTERFACe s_axilite port = hash bundle = CRTLS

  //STEP1:
  textToBinary(input, hash); //converts text to binary

  append_f(hash); //appends 1 and 0 to make input a multipule of 512

  //STEPs2&3:

  //the fractions of the sqaure roots of the 1st 8 prime numbers.
  char * H0 = "0x6a09e667";
  char * H1 = "0xbb67ae85";
  char * H2 = "0x3c6ef372";
  char * H3 = "0xa54ff53a";
  char * H4 = "0x510e527f";
  char * H5 = "0x9b05688c";
  char * H6 = "0x1f83d9ab";
  char * H7 = "0x5be0cd19";

  //setting the hash values h0 through h7 to be equal to the binary from of the fractions of the sqaure roots of the 1st 8 prime numbers.
  hexToBin(H0, h0);
  hexToBin(H1, h1);
  hexToBin(H2, h2);
  hexToBin(H3, h3);
  hexToBin(H4, h4);
  hexToBin(H4, h0);
  hexToBin(H5, h5);
  hexToBin(H6, h6);
  hexToBin(H7, h7);

  //end of h value creation

  //steps4&5&6&7
  rounds(hash);
  printf("Final H values:\n");
  printf("h0: %s\n", h0);
  printf("h1: %s\n", h1);
  printf("h2: %s\n", h2);
  printf("h3: %s\n", h3);
  printf("h4: %s\n", h4);
  printf("h5: %s\n", h5);
  printf("h6: %s\n", h6);
  printf("h7: %s\n", h7);
  //step8
  finalHash(hash);

  return hash;

}

//STEP 1 Functions:

void textToBinary(char * input, char * output) {

  size_t length = len(input);
  output[0] = '\0';
  for (size_t i = 0; i < length; ++i) {
    char ch = input[i];
    for (int j = 7; j >= 0; --j) {
      if (ch & (1 << j)) {
        cat(output, "1");
      } else {
        cat(output, "0");
      }
    }
  }
}
//appends 1 and 0 to make input a multipule of 512:
void append_f(char * input) {
  //length of the original input string
  int length = len(input);
  // the remainder after dividing the length of the string by 512
  int rem_512 = length % 512;
  int new_length = length + (512 - rem_512);

  //this is final hash that would be produced
  char message_block[new_length];

  catc(input, '1');
  int i = length + 1;
  for (i = length + 1; i < new_length - 64; i++) {
    input[i] = '0';
  }
  //    printf("Length: %d\n",i);
  uint64_t l = length;
  char leng[65];
  char leng2[65];
  binaryRep64(l, leng);
  leng[64] = '\0';
  int k = 0;
  while (k < 32) {
    catc(leng2, '0');
    k++;
  }
  leng[32] = '\0';
  int b = 0;
  while (k < 64) {
    leng2[k] = leng[b];
    k++;
    b++;
  }
  leng2[64] = '\0';
  int j = 0;
  while (leng2[j] != '\0') {
    input[i] = leng2[j];
    i++;
    j++;
  }
  input[i] = '\0';
  //    printf("Length: %d\n",i);
  //    printf("%s\n",input);
}

char * hexToBin(char * string, char * bits) {
  int i = 0;
  while (string[i] != '\0') { //loopes through the hex string
    if (i > 1) {
      cat(bits, hToB(string[i])); //concatnates the new binary string
    }
    i++;
  }

  return bits;
}

//converts a hex digit to a binary string
char * hToB(char oneHex) {
  switch (oneHex) {
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

//step 4
char * rounds(char * fullPaddedMessage) {
  int i = 0;
  int c = 0;
  int index = 0;
  char currentInt[513] = "";
  uint32_t bitArray[64];
  while (fullPaddedMessage[i] != '\0') {
    catc(currentInt, fullPaddedMessage[i]);
    //   printf("%d\n",i);
    if (c == 511) {
      currentInt[c + 1] = '\0';
      //   printf("%s\n",currentInt);
      createMessageScheduling(currentInt, bitArray);
      step6(bitArray);
      int l = 0;
      //   while(l<64){
      //     //  char b[33];
      //     //  binaryRep(bitArray[l],b);
      //     //  printf("%s\n",b);
      //     printf("%u\n",bitArray[l]);
      //     l++;
      //   }
      step7();
      c = 0;
      currentInt[0] = '\0';
    } else {
      c++;
    }
    i++;
  }
  //   finalHash(fullPaddedMessage);
  return fullPaddedMessage;
}

//step 5

int createMessageScheduling(char * bitsString, uint32_t bitArray[64]) {
  char stringBitArray[64][34];
  makeArrayOfBitStrings(bitsString, stringBitArray);
  //call a function that populates the bitArray with the values of int value of stringBitArray using bitsTo32Ints
  makeArrayOfBitInts(stringBitArray, bitArray);
  //adding 48 more words (i.e. 48 more uint32_t elements)
  add48Ints(bitArray);
  //now, bitArray can be used to preform the operations of step 5.
  modify(bitArray);
  return 0;
}

void makeArrayOfBitInts(char stringBitArray[64][34], uint32_t bitArray[64]) {
  int i = 0;
  for (i = 0; i < 16; i++) {
    // printf ("%s\n", stringBitArray[i]);
    bitArray[i] = bitsTo32Ints(stringBitArray[i]);
  }
}

void makeArrayOfBitStrings(char * bitsString, char stringBitArray[64][34]) {
  int i = 0;
  int c = 0;
  int index = 0;
  char currentInt[99] = "";
  while (bitsString[i] != '\0') {
    //  printf ("%d\n", i);
    //   printf ("%c\n", bitsString[i]);
    catc(currentInt, bitsString[i]);
    //printf ("%s\n", currentInt);
    if (c == 31) {
      currentInt[c + 1] = '\0';
      stringBitArray[index][c + 1] = '\0';
      cpy(stringBitArray[index], currentInt);
      //currentInt[c] = '\0';
      c = 0;
      currentInt[0] = '\0';
      index++;
    } else {
      c++;
    }

    i++;

  }
}

void add48Ints(uint32_t bitArray[64]) {
  int i = 16;
  for (i = 16; i < 64; i++) {
    bitArray[i] = 0;
  }
}

void modify(uint32_t ints[64]) {
  int i = 0;
  for (i = 16; i < 64; i++) { //fix
    uint32_t w1rr7 = ints[i - 15];
    uint32_t w1rr18 = ints[i - 15];
    uint32_t w1rs3 = ints[i - 15];
    w1rr7 = right_rotate(w1rr7, 7);
    w1rr18 = right_rotate(w1rr18, 18);
    w1rs3 = right_shift(w1rs3, 3);

    uint32_t w14rr17 = ints[i - 2];
    uint32_t w14rr19 = ints[i - 2];
    uint32_t w14rs10 = ints[i - 2];
    w14rr17 = right_rotate(w14rr17, 17);
    w14rr19 = right_rotate(w14rr19, 19);
    w14rs10 = right_shift(w14rs10, 10);

    uint32_t s0 = xor(xor(w1rr7, w1rr18), w1rs3);
    uint32_t s1 = xor(xor(w14rr17, w14rr19), w14rs10);
    ints[i] = ints[i - 16] + s0 + ints[i - 7] + s1;
  }
}


//string to int32_t
uint32_t bitsTo32Ints(char * string) {
  uint32_t x = 0;
  int i = 0;
  uint32_t t = 1;
  uint32_t total = 0;
  for (i = 31; i >= 0; i--) {
    // printf("%d",i);
    int oz = string[i] - 48;
    // printf("%d\n",oz);
    if (oz == 1) {
      total = total + t;
    }
    t = t * 2;
  }
  return total;
}

//step 6 functions

void step6(uint32_t w[64]) {
  a = bitsTo32Ints(h0);
  b = bitsTo32Ints(h1);
  c = bitsTo32Ints(h2);
  d = bitsTo32Ints(h3);
  e = bitsTo32Ints(h4);
  f = bitsTo32Ints(h5);
  g = bitsTo32Ints(h6);
  h = bitsTo32Ints(h7);
//   printf("%u\n",a);
//   printf("%u\n",b);
//   printf("%u\n",c);
//   printf("%u\n",d);
//   printf("%u\n",e);
//   printf("%u\n",f);
//   printf("%u\n",g);
//   printf("%u\n",h);


  int i = 0;

  uint32_t S1 = 0;

  uint32_t ch = 0;

  uint32_t kint = 0;
  uint32_t temp1 = 0;

  uint32_t S0 = 0;

  uint32_t maj = 0;

  uint32_t temp2 = 0;
  for (i = 0; i < 64; i++) {


    S1 = (rightRotate(e, 6)) ^ (rightRotate(e, 11)) ^ (rightRotate(e, 25));

    ch = xor((e & f), ((~e) & g));
    hexToBin(K[i], k[i]);
    kint = bitsTo32Ints(k[i]);
    // printf("%d: k value in hex: %s\n",i, K[i]);
    // printf("K in binary: %s\n",k[i]);
    // printf("K in uint: %u\n",kint);
    temp1 = h + S1 + ch + kint + w[i];


    S0 = (rightRotate(a, 2)) ^ (rightRotate(a, 13)) ^ (rightRotate(a, 22));

    maj = (a & b) ^ (a & c) ^ (b & c);

    temp2 = S0 + maj;

    h = g;
    g = f;
    f = e;
    e = d + temp1;
    d = c;
    c = b;
    b = a;
    a = temp1 + temp2;

    //    if(i==0){
    //    printf("First round: \n"); 
    //    printf("Vars: %u\n",a);
    //    printf("Vars: %u\n",b);
    //    printf("Vars: %u\n",c);
    //    printf("Vars: %u\n",d);
    //    printf("Vars: %u\n",e);
    //    printf("Vars: %u\n",f);
    //    printf("Vars: %u\n",g);
    //    printf("Vars: %u\n",h);
    //    }

  }
     printf("Last round: \n"); 
    //  char b1[32];
    //  printf("Vars: %s\n",binaryRep(a,b1));
     printf("Vars: %u\n",a);
     printf("Vars: %u\n",b);
     printf("Vars: %u\n",c);
     printf("Vars: %u\n",d);
     printf("Vars: %u\n",e);
     printf("Vars: %u\n",f);
     printf("Vars: %u\n",g);
     printf("Vars: %u\n",h);
}

//step7
//32 bits
char * binaryRep(uint32_t n, char * binary) {
  uint32_t mask = 0x80000000;
  binary[0] = '\0';
  while (mask) {
    char a = (n & mask) ? '1' : '0';
    catc(binary, a);

    mask = mask >> 1;
  }

  return binary;
}
//64 bits
char * binaryRep64(uint64_t n, char * binary) {
  uint32_t mask = 0x80000000;
  binary[0] = '\0';
  while (mask) {
    char a = (n & mask) ? '1' : '0';
    catc(binary, a);

    mask = mask >> 1;
  }

  return binary;
}

void addstep7(char * hex, uint32_t x) {

  uint32_t temp = bitsTo32Ints(hex) + x;
  binaryRep(temp, hex);

}

void step7() {
  addstep7(h0, a);
  addstep7(h1, b);
  addstep7(h2, c);
  addstep7(h3, d);
  addstep7(h4, e);
  addstep7(h5, f);
  addstep7(h6, g);
  addstep7(h7, h);
  //    printf ("%s\n", h0);
  //    printf ("%s\n", h1);
  //    printf ("%s\n", h2);
  //    printf ("%s\n", h3);
  //    printf ("%s\n", h4);
  //    printf ("%s\n", h5);
  //    printf ("%s\n", h6);
  //    printf ("%s\n", h7);
}

//step8
char * BToh(char * input, char * output) {

  for (int i = 0; i < 32; i = i + 4) {

    // char append = '';
    char test[5] = "";

    catc(test, input[i]);
    catc(test, input[i + 1]);
    catc(test, input[i + 2]);
    catc(test, input[i + 3]);

    char * zero = "0000";
    char * one = "0001";
    char * two = "0010";
    char * three = "0011";
    char * four = "0100";
    char * five = "0101";
    char * six = "0110";
    char * seven = "0111";
    char * eight = "1000";
    char * nine = "1001";
    char * A = "1010";
    char * B = "1011";
    char * C = "1100";
    char * D = "1101";
    char * E = "1110";
    char * F = "1111";

    if (equivalent1(zero, test)) {
      catc(output, '0');
    } else if (equivalent1(one, test)) {
      catc(output, '1');
    } else if (equivalent1(two, test)) {
      catc(output, '2');
    } else if (equivalent1(three, test)) {
      catc(output, '3');
    } else if (equivalent1(four, test)) {
      catc(output, '4');
    } else if (equivalent1(five, test)) {
      catc(output, '5');
    } else if (equivalent1(six, test)) {
      catc(output, '6');
    } else if (equivalent1(seven, test)) {
      catc(output, '7');
    } else if (equivalent1(eight, test)) {
      catc(output, '8');
    } else if (equivalent1(nine, test)) {
      catc(output, '9');
    } else if (equivalent1(A, test)) {
      catc(output, 'A');
    } else if (equivalent1(B, test)) {
      catc(output, 'B');
    } else if (equivalent1(C, test)) {
      catc(output, 'C');
    } else if (equivalent1(D, test)) {
      catc(output, 'D');
    } else if (equivalent1(E, test)) {
      catc(output, 'E');
    } else if (equivalent1(F, test)) {
      catc(output, 'F');
    } else {

    }
  }

  return output;
}

bool equivalent(char * Str1, char * Str2) {
  int result, i;
  i = 0;
  while (Str1[i] == Str2[i] && Str1[i] == '\0') {
    i++;

    if (Str1[i] != Str2[i]) {
      return false;
    }
  }
  return true;
}

bool equivalent1(char * dest, char * neww) {
  for (int i = 0; i < 4; i++) {
    if (dest[i] != neww[i]) {
      return false;
    }
  }

  return true;
}

char * finalHash(char * input) {
  input[0] = '\0';
  // printf("h0: %s\n",h7);
  // printf("Initial Input %s\n",input);
  char finalH0[9] = "";
  BToh(h0, finalH0);
  finalH0[8] = '\0';
  // printf("H0: %s\n",finalH0);
  cat(input, finalH0);
  input[8] = '\0';
  // printf("Final Input %s\n",input);

  // printf("Initial Input %s\n",input);
  char finalH1[9] = "";
  BToh(h1, finalH1);
  finalH1[8] = '\0';
  // printf("H1: %s\n",finalH1);
  cat(input, finalH1);
  input[16] = '\0';
  // printf("Final Input %s\n",input);

  // printf("Initial Input %s\n",input);
  char finalH2[9] = "";
  BToh(h2, finalH2);
  finalH2[8] = '\0';
  // printf("H2: %s\n",finalH2);
  cat(input, finalH2);
  input[24] = '\0';
  // printf("Final Input %s\n",input);

  char finalH3[9] = "";
  BToh(h3, finalH3);
  finalH3[8] = '\0';
  cat(input, finalH3);
  input[32] = '\0';

  char finalH4[9] = "";
  BToh(h4, finalH4);
  finalH4[8] = '\0';
  cat(input, finalH4);
  input[40] = '\0';

  char finalH5[9] = "";
  BToh(h5, finalH5);
  finalH5[8] = '\0';
  cat(input, finalH5);
  input[48] = '\0';

  char finalH6[9] = "";
  BToh(h6, finalH6);
  finalH6[8] = '\0';
  cat(input, finalH6);
  input[56] = '\0';

  char finalH7[9] = "";
  BToh(h7, finalH7);
  finalH7[8] = '\0';
  cat(input, finalH7);
  input[64] = '\0';

  // printf("Out put%s\n",input);

  return input;

}

//helper functions

uint32_t rightRotate(uint32_t num, int n) {
  uint32_t result=num;
  return (result >> n) | (result << (32 - n));
}

uint32_t right_shift(uint32_t num, int n) {
  return num >> n;
}
uint32_t right_rotate(uint32_t num, int n) {
  return (num >> n) | (num << (32 - n));
}

int xor(uint32_t a, uint32_t b) {
  return a ^ b;
}

char * catc(char * dest, char new) {
  int i = 0;
  int j = 0;
  i = len(dest);
  dest[i] = new;
  dest[i + 1] = '\0';
  return dest;
}

void cpy(char * dest, char * source) {
  int i = 0;
  while (source[i] != '\0') {
    dest[i] = source[i];
    i = i + 1;
  }
}

int len(char * txt) {
  int i = 0;
  while (txt[i] != '\0') {
    i++;
  }
  return i;
}

void cat(char * dest, char * new) {
  int i = 0;
  int j = 0;
  i = len(dest);
  while (new [j] != '\0') {
    dest[i] = new [j];
    i++;
    j++;
  }
}