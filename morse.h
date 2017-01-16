#pragma once
#define MORSE_SPACE       0b0
#define MORSE_DOT         0b10   
#define MORSE_DASH        0b11 
/*
	Concatenate two morse code.

	Ex:
	long a = MORSE_DOT; // 0b10 
	long b = MORSE_DASH;// 0b11
	conca(a,b);
	>> 0b1011

*/
long conca(long a, long b);

/*
	Converting morse which is a long, to a char.

	Ex:
	long m = 0b111111; // 0b111111 <=> 'o'
	morseToChar(m);
	>> 'o'

*/
char morseToChar(long m);

/*
	Converting string to morse (binary)

	Ex:
	char * test = "ab";
	morseToChar(test);
	>> 0b1011011101010

*/
long stringToMorse(char* r);

/*
	Converting a charactere to morse code in binary 
	

	Ex:
	char ch= 'o';
	charToMorse(ch);
	>> 0b111111

*/
long charToMorse(char r);

/*
	Converting binary code of morse to a list of morse code (deconcatenate).
	return size list : arg int* size
	

	Ex:
	long l = 172533532722532277;
	int * size = (int*) malloc(sizeof(int));
	binaryToMorse(l, size);
	>> mvxlvej

*/
long* binaryToMorse(long l, int* size);

/*
	Decimal to a list of binary
	return size list : arg int* size

	Ex:
	long l = 0b10;
	int * size = (int*) malloc(sizeof(int));
	binaryToMorse(l, size);
	>> {1,0]

*/
long* convertDecimalToBinary(long n, int* size);

/*
	Convert binary list of morse code to string
	

	Ex:
	long* l = (long*) malloc(sizeof(long)*2);
	*l=0b1011; // a
	l++;
	*l=0b11101010; // b
	l--;
	int size=2;
	binaryToMorseChar(l, size);
	>> "ab"

*/
char * binaryToMorseChar(long* l, int size);


