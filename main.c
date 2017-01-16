#include "morse.h"
#include "clean.h"
#include "cryptage.h"
#include <stdio.h>
#include <string.h>

#include <stdlib.h>

int main() {
  printf("\n\n");
	
char*  input_string[100];
	while (strncmp(input_string,"quit",4)) {
	
	    scanf("%[^\n]s",&input_string);
	   
	    printf("%s",input_string);
    }


	char* entre = "jesuisunbg"; // Message à coder
	char * crypt = cryptage(entre); // On crypte le message d'entrée
	printf("%S",crypt); 
	
	printf("%s\n", byte_to_binary(stringToMorse(crypt))); 

	/*
	char* entre = "jesuis";
	
	char sortie[42];
	printf("%s\n",entre);
	transString(entre,sortie);
	printf("%s\n",sortie);
	char* sortie2=cryptage(sortie);
	printf("%s\n",sortie2);
	long aaa = stringToMorse(sortie2);
	printf("%lo\n",aaa);
	
	int* size=(int*) malloc(sizeof(int));
	int* rep = binaryToMorse(aaa, size);
	
	
	

	printf("\n\n");
	   return 0;
	
	*/
printf("\n\n");
   return 0;
}
