#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converting char c to char out in a simplified alphabet. 
Return 2 if c is special, 1 if c is a capital letter et 0 if c is in the simplified alphabet. */
int transChar(char c, char* out){
	if (c < 33 || c == 35 || c == 37 || c == 42 || c == 60 || c == 62 || c == 91 || c == 92|| c == 93 || c == 94|| c == 96 || c > 122)
	{
		return 2;
		//Char c is not in the simplified alphabet
	}
	else if( c>64 && c<91)
	{
		*out = c+32;
		return 1;
		//Char c is a capital letter
	}
	else
	{
		*out =c;
		return 0;
		//Char c is in the simplified alphabet
	}
}

/*converting the string s to string out in the simplified alphabet.
Return 1 if s != out, or else 0.

Exemple:
char* s = "Je suis un ananas!******";
char* out;
int b = transString(s,out);

>>> s = "Je suis un ananas!******";
	out = "jesuisunananas!"
	b = 1; (car s != out)

*/
int transString(char* s, char* out){
	
	int erreur;
	int errone = 0;
	int i;
	char c;
	char caractere;
	strcpy(out, "");
	
	int j = 0;
	for (i = 0; i< strlen(s); ++i)
	{
            caractere = s[i];
			erreur = transChar(caractere,&c);
			if(erreur != 2){
				out[j] = c;
				j = j+1;			
			} //Erreur take the value described in transChar.
		
			if(erreur !=0 && errone == 0){
				errone = 1;
			};
	}
	
	out[j] = '\0';
	
	return errone;
}


