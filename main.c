#include "morse.h"
#include "cryptage.h"
#include <stdio.h>


int main() {
  printf("\n\n");
	
	

	char* entre = "jesuisunbg";
	char * crypt = cryptage(entre);
	printf("%S",crypt);
	
	printf("%s\n", byte_to_binary(stringToMorse(crypt)));
	



printf("\n\n");
   return 0;
}
