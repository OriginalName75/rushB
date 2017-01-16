#include "morse.h"
#include "cryptage.h"
#include <stdio.h>


int main() {
  printf("\n\n");
	
	

	char* entre = "jesuisunbg"; // Message à coder
	char * crypt = cryptage(entre); // On crypte le message d'entrée
	printf("%S",crypt); 
	
	printf("%s\n", byte_to_binary(stringToMorse(crypt))); 
	



printf("\n\n");
   return 0;
}
