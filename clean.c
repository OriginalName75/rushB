#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*convertit char c en un caractere out conforme a l'alphabet simplifie. 
Renvoie 2 si le caractere c est special, 1 si c'est une majuscule et 0 s'il est déja conforme. */
int transChar(char c, char* out){
	if (c < 33 || c == 35 || c == 37 || c == 42 || c == 60 || c == 62 || c == 91 || c == 92|| c == 93 || c == 94|| c == 96 || c > 122)
	{
		return 2;
		//Caractere non traite dans notre reduction du langage
	}
	else if( c>64 && c<91)
	{
		*out = c+32;
		return 1;
		//Caractere majuscule converti en minuscule
	}
	else
	{
		*out =c;
		return 0;
		//Caractere minuscule ou special inclus dans notre reduction du langage
	}
}

/*convertit le string s en un string out conforme a l'alphabet simplifie.
Renvoie 1 si le texte out est different de s, 0 sinon.

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
			} //Erreur prend la valeur du retour de transChar precise precedemment.
		
			if(erreur !=0 && errone == 0){
				errone = 1;
			}; //Si le texte est modifie, errone passe a 1.
	}
	
	out[j] = '\0';
	
	return errone;
}


