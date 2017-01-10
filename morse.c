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
