#pragma once
#define MORSE_SPACE       0b0
#define MORSE_DOT         0b10   
#define MORSE_DASH        0b11 


const char* byte_to_binary();
long stringToMorse(char* r);
int* binaryToMorse(long l, int* size);
char* binaryToMorseChar(long l, int* size);
long charToMorse(char r);
char morseToChar(long m);

long conca(long a, long b);



