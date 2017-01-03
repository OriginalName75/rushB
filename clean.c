#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int transChar(char c, char* out){
	if (c < 33 || c == 35 || c == 37 || c == 42 || c == 60 || c == 62 || c == 91 || c == 92|| c == 93 || c == 94|| c == 96 || c > 122)
	{
		return 2;
	}
	else if( c>64 && c<91)
	{
		*out = c+32;
		return 1;
	}
	else
	{
		*out =c;
		return 0;	
	}
}

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
			}
			if(erreur !=0 && errone == 0){
				errone = 1;
			};
	}
	out[j] = '\0';
	return errone;
}

int main()
{
	
	FILE* entree = fopen("entree.txt", "r+");
	int erreur;
	int errone;
	char c;
	char caractere;
    if (entree != NULL)
    {
        // On peut lire et écrire dans le fichier
		FILE* clair = fopen("clair.txt", "w");
		do
        {
            caractere = fgetc(entree);
			erreur = transChar(caractere,&c);
			if(erreur != 2){
				fputc(c,clair);
			}
			if(erreur !=0 && errone == 0){
				errone = 1;
			}            
			//printf("%c", caractere);
        } while (caractere != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
		
		
		fclose(clair);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier entree.txt");
    }	
	fclose(entree);

	char sortie[128];

	transString("Je suis un Ananas!***",sortie);
	printf(sortie);


	return 0;

}



