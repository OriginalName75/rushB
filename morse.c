#include "morse.h"

#include <string.h>


const char* byte_to_binary(int x)
{
    static char b[20];
    b[0] = '\0';

    int z;
    for (z = 128*128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}


long conca(long a, long b) {
	
	long mult = 1; 
	int plus = 0;
	 while(mult <= b) {
		plus++;
		mult = 2*mult;
		
	}
	

	return a <<plus | b ;
}

long stringToMorse(char* r) {
	long rep=0;
	int i;
	for (i = 0; i < strlen(r); i++){
		rep=conca(conca(rep,MORSE_SPACE),charToMorse(r[i]));
		// espace mis
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


		
		default: 

		 rep=MORSE_SPACE;

	}
	return rep;



}
