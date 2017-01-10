#include "morse.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void getBin(int num, char *str)
{
  *(str+5) = '\0';
  int mask = 0x10 << 1;
  while(mask >>= 1)
    *str++ = !!(mask & num) + '0';
}
int* convertDecimalToBinary(long n, int* size)
{
    
    int* binaryNumber = malloc(800*sizeof(int));
    int remainder, i = 1, step = 0;
	int l=0;
    while (n!=0)
    {
        remainder = n%2;
	binaryNumber[step] = remainder;
	 
        step++;
        n = n/2;
       l++;
        i *= 10;
    }
	
	 int* rep = malloc(l*sizeof(int));
	i=0;
	 
	binaryNumber+=l-1;
	while (i<l) {
		*rep=*binaryNumber;
		 
		rep++;
		binaryNumber--;
		i++;
	}
	rep-=l;
	*size=l;
    return rep;
}
const char* byte_to_binary(int x)
{
    static char b[200];
    b[0] = '\0';

    int z;
    for (z = pow(2,23); z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}
char* binaryToMorseChar(long l, int* size) {

	int* i =binaryToMorse(l, size);
	int j;
	long memory=0;
	for (j=0;j<*size;j++) {
		if (i==MORSE_SPACE) {
			memory=0;
		}else {
			if (memory==0) {
				memory=*i;
			}else {
				memory=conca(memory,*i);
			}
			
		}
		i++;
	}
	return rep;

}
int* binaryToMorse(long l, int* size) {
	
	
	int* sizee = (int*) malloc(sizeof(int));
	
	int* i = convertDecimalToBinary(l,sizee);
	
	int* rep = (int*) malloc(sizeof(int)*(*sizee));
	int k=0;
	int first=0;
	while (k<*sizee) {
		if (first==0) {
			if (*i==0) {
				
				*rep=MORSE_SPACE;
				rep++;
				*size=*size+1;
			}else {
				first=1;
			}	
		 }else  {
		if (*i==0) {
			
			*rep=MORSE_DOT;
			rep++;
			*size=*size+1;
		}else {
			
			*rep=MORSE_DASH ;
			rep++;
			*size=*size+1;
		}
			first=0;
		}
		k++;
		i++;
	}
    	rep-=*size;
	
	return rep;

}

long conca(long a, long b) {
	
	long mult = 1; 
	int plus = 0;
	if (b==0) {
	plus=1;
	}else {
	 while(mult <= b) {
		plus++;
		mult = 2*mult;
		
	}
	}

	return a <<plus | b ;
}

long stringToMorse(char* r) {
	long rep=0;
	int i;
	for (i = 0; i < strlen(r); i++){
		
		rep=conca(conca(rep, MORSE_SPACE),charToMorse(r[i]));
		
	}

	return rep;
}

long charToMorse(char r) {
	long rep=0;
	switch (r) {

		case 'a' :
			rep=conca(MORSE_DOT,MORSE_DASH);	

		break;
		
		case 'b' :
			rep=conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DOT),MORSE_DOT);	

		break;
		
		case 'c' :
			rep=conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DASH),MORSE_DOT);	

		break;

		case 'd' :
			rep=conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DASH);	

		break;
		
		case 'e' :
			rep=MORSE_DOT;	

		break;

		case 'f' :
			rep=conca(conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DASH),MORSE_DOT);		

		break;

		case 'g' :
			rep=conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DOT);		

		break;

		case 'h' :
			rep=conca(conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DOT),MORSE_DOT);		

		break;

		case 'i' :
			rep=conca(MORSE_DOT,MORSE_DOT);		

		break;

		case 'j' :
			rep=conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DASH),MORSE_DASH);		

		break;

		case 'k' :
			rep=conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DASH);		

		break;

		case 'l' :
			rep=conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DOT),MORSE_DOT);		

		break;

		case 'm' :
			rep=conca(MORSE_DASH,MORSE_DASH);		

		break;	

		case 'n' :
			rep=conca(MORSE_DASH,MORSE_DOT);		

		break;	

		case 'o' :
			rep=conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DASH);		

		break;		


		case 'p' :
			rep=conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DASH),MORSE_DOT);			

		break;	

		case 'q' :
			rep=conca(conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DOT),MORSE_DASH);			

		break;	

		case 'r' :
			rep=conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DOT);		

		break;	

		case 's' :
			rep=conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DOT);		

		break;	

		case 't' :
			rep=MORSE_DASH;		

		break;	
		
		case 'u' :
			rep=conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DASH);		

		break;	
		
		case 'v' :
			rep=conca(conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DOT),MORSE_DASH);		

		break;	

		case 'w' :
			rep=conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DASH);		

		break;	

		case 'x' :
			rep=conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DOT),MORSE_DASH);	

		break;	

		case 'y' :
			rep=conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DASH),MORSE_DASH);			

		break;	
		
		case 'z' :
			rep=conca(conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DOT),MORSE_DOT);			

		break;	

		case '0' :
			rep=conca(conca(conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DASH),MORSE_DASH),MORSE_DASH);

		break;
		
		case '1' :
			rep=conca(conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DASH),MORSE_DASH),MORSE_DASH);			

		break;
			
		
		case '2' :
			rep=conca(conca(conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DASH),MORSE_DASH),MORSE_DASH);		

		break;	

		case '3' :
			rep=conca(conca(conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DOT),MORSE_DASH),MORSE_DASH);		

		break;	

		case '4' :
			rep=conca(conca(conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DOT),MORSE_DOT),MORSE_DASH);	

		break;	

		case '5' :
			rep=conca(conca(conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DOT),MORSE_DOT),MORSE_DOT);			

		break;	
		
		case '6' :
			rep=conca(conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DOT),MORSE_DOT),MORSE_DOT);			

		break;	

		case '7' :
			rep=conca(conca(conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DOT),MORSE_DOT),MORSE_DOT);

		break;
		
		case '8' :
			rep=conca(conca(conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DASH),MORSE_DOT),MORSE_DOT);			

		break;	
			
		case '9' :
			rep=conca(conca(conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DASH),MORSE_DASH),MORSE_DOT);		

		break;
		
		case '.' :
			rep=conca(conca(conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DOT),MORSE_DASH),MORSE_DOT),MORSE_DASH);			

		break;
			
		
		case ',' :
			rep=conca(conca(conca(conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DOT),MORSE_DOT),MORSE_DASH),MORSE_DASH);		

		break;	

		case '?' :
			rep=conca(conca(conca(conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DASH),MORSE_DASH),MORSE_DOT),MORSE_DOT);			

		break;	

		case '\'' :
			rep=conca(conca(conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DASH),MORSE_DASH),MORSE_DASH),MORSE_DOT);		

		break;	

		case '!' :
			rep=conca(conca(conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DASH),MORSE_DOT),MORSE_DASH),MORSE_DASH);			

		break;	
		
		case '/' :
			rep=conca(conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DOT),MORSE_DASH),MORSE_DOT);

		break;
		
		case '(' :
			rep=conca(conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DASH),MORSE_DASH),MORSE_DOT);			

		break;	
			
		case ')' :
			rep=conca(conca(conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DASH),MORSE_DASH),MORSE_DOT),MORSE_DASH);			

		break;	
			
		case '&' :
			rep=conca(conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DOT),MORSE_DOT),MORSE_DOT);		

		break;	
			
		case ':' :
			rep=conca(conca(conca(conca(conca(MORSE_DASH,MORSE_DASH),MORSE_DASH),MORSE_DOT),MORSE_DOT),MORSE_DOT);			

		break;
			
		case ';' :
			rep=conca(conca(conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DASH),MORSE_DOT),MORSE_DASH),MORSE_DOT);			

		break;	
		
		case '=' :
			rep=conca(conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DOT),MORSE_DOT),MORSE_DASH);			

		break;	
			
		case '+' :
			rep=conca(conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DOT),MORSE_DASH),MORSE_DOT);			

		break;	
			
		case '-' :
			rep=conca(conca(conca(conca(conca(MORSE_DASH,MORSE_DOT),MORSE_DOT),MORSE_DOT),MORSE_DOT),MORSE_DASH);			

		break;	
			
		case '_' :
			rep=conca(conca(conca(conca(conca(MORSE_DOT,MORSE_DOT),MORSE_DASH),MORSE_DASH),MORSE_DOT),MORSE_DASH);			

		break;		
			
		case '"' :
			rep=conca(conca(conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DOT),MORSE_DOT),MORSE_DASH),MORSE_DOT);			

		break;	
			
		case '$' :
			rep=conca(conca(conca(conca(conca(conca( MORSE_DOT,MORSE_DOT),MORSE_DOT),MORSE_DASH),MORSE_DOT),MORSE_DOT),MORSE_DASH);			

		break;		
			
		case '@' :
			rep=conca(conca(conca(conca(conca(MORSE_DOT,MORSE_DASH),MORSE_DASH),MORSE_DOT),MORSE_DASH),MORSE_DOT);			

		break;		
		
		default: 

		 rep=MORSE_SPACE;

	}
	return rep;



}

char morseToChar(long m) {
	char c;
	switch (r) {

		case 0b1011 :
			c='a';	

		break;
		
		case 0b11101010 :
			c='b';	

		break;
		
		case 0b11101110 :
			c='c';
			
		break;

		case 0b111011 :
			c='d';
			
		break;
		
		case 0b10 :
			c='e';

		break;

		case 0b10101110 :
			c='f';
			
		break;

		case 0b111110 :
			c='g';
			
		break;

		case 0b10101010 :
			c='h';
			
		break;

		case 0b1010 :
			c='i';
			
		break;

		case 0b10111111 :
			c='j';
			
		break;

		case 0b111011 :
			c='k';
			
		break;

		case 0b10111010 :
			c='l';
			
		break;

		case 0b1111 :
			c='m';
			
		break;	

		case 0b1110 :
			c='n';
			
		break;	

		case 0b111111 :
			c='o';
			
		break;		


		case 0b10111110 :
			c='p';
			
		break;	

		case 0b11111011 :
			c='q';
			
		break;	

		case 0b101110 :
			c='r';
			
		break;	

		case 0b101010 :
			c='s';
			
		break;	

		case 0b11 :
			c='t';
			
		break;	
		
		case 0b101011 :
			c='u';
			
		break;	
		
		case 0b10101011 :
			c='v';
			
		break;	

		case 0b101111 :
			c='w';
			
		break;	

		case 0b11101011 :
			c='x';
			
		break;	

		case 0b11101111 :
			c='y';
			
		break;	
		
		case 0b11111010 :
			c='z';
			
		break;	

		case 0b1111111111 :
			c='0';
			
		break;
		
		case 0b1011111111 :
			c='1';
			
		break;
			
		
		case 0b1010111111 :
			c='2';
			
		break;	

		case 0b1010101111 :
			c='3';
			
		break;	

		case 0b1010101011 :
			c='4';
			
		break;	

		case 0b1010101010 :
			c='5';
			
		break;	
		
		case 0b1110101010 :
			c='6';
			
		break;	

		case 0b1111101010 :
			c='7';
			
		break;
		
		case 0b1111111010 :
			c='8';
			
		break;	
			
		case 0b1111111110 :
			c='9';
			
		break;
		
		case 0b101110111011 :
			c='.';
			
		break;
			
		
		case 0b111110101111 :
			c=',';
			
		break;	

		case 0b101011111010 :
			c='?';
			
		break;	

		case 0b101111111110 :
			c='\'';
			
		break;	

		case 0b111011101111 :
			c='!';
			
		break;	
		
		case 0b1110101110 :
			c='/';
			
		break;
		
		case 0b1110111110 :
			c='(';
			
		break;	
			
		case 0b111011111011 :
			c=')';
			
		break;	
			
		case 0b1011101010 :
			c='&';	

		break;	
			
		case 0b111111101010 :
			c=':';

		break;
			
		case 0b111011101110 :
			c=';';

		break;	
		
		case 0b1110101011 :
			c='=';			

		break;	
			
		case 0b1011101110 :
			c='+';		

		break;	
			
		case 0b111010101011 :
			c='-';		

		break;	
			
		case 0b101011111011 :
			c='_';		

		break;		
			
		case 0b101110101110 :
			c='"';

		break;	
			
		case 0b10101011101011 :
			c='$';
			
		break;		
			
		case 0b101111101110 :
			c='@';			

		break;		
		
		default: 

		 c=' ';

	}
	return rep;



}
