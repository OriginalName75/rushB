#include "cryptage.h" 
#include <string.h>
#include <stdlib.h>


// Use the Cesar cipher on the char c, 
// return c+3

int find(char r, char* table) {
	int i;
	for (i=0; i<54;i++) {
		if (table[i]==r) {
			return (i+3)%54;
		}
	}
	return 0;
}

// Cypher the string r
char* cryptage(char* r) {
char table[54]; 
	
// Our cipher table of 54 characters
	table[0] = 'a';
	table[1] = 'b';
	table[2] = 'c';
	table[3] = 'd';
	table[4] = 'e';
	table[5] = 'f';    
	table[6] = 'g';
	table[7] = 'h';
	table[8] = 'i';
	table[9] = 'j';
	table[10] = 'k';   
	table[11] = 'l';
	table[12] = 'm';
	table[13] = 'n';
	table[14] = 'o';
	table[15] = 'p';    
	table[16] = 'q';
	table[17] = 'r';
	table[18] = 's';
	table[19] = 't';
	table[20] = 'u';   
	table[21] = 'v';
	table[22] = 'w';
	table[23] = 'x';
	table[24] = 'y';
	table[25] = 'z';   
	table[26] = '0';
	table[27] = '1';
	table[28] = '2';
	table[29] = '3';
	table[30] = '4';
	table[31] = '5';
	table[32] = '6';    
	table[33] = '7';
	table[34] = '8';
	table[35] = '9';
	table[36] = '.';
	table[37] = ',';   
	table[38] = '?';
	table[39] = '\'';
	table[40] = '!';
	table[41] = '/';
	table[42] = '(';    
	table[43] = ')';
	table[44] = '&';
	table[45] = ':';
	table[46] = ';';
	table[47] = '=';   
	table[48] = '+';
	table[49] = '-';
	table[50] = '_';
	table[51] = '\"';
	table[52] = '$';
	table[53] = '@';
	char * rep = malloc(strlen(r));

	// Use the cipher on our string
	int i;
	for (i = 0; i < strlen(r); i++){
		rep[i]=table[find(r[i],table)];
		
		
	}
	return rep;
}

//Decipher using the same method (-3)
int defind(char r, char* table) {


	
	int i;
	for (i=0; i<54;i++) {
		if (table[i]==r) {
			return (i-3)%54;
		}
	}
	return 0;
}

//Decypher the string r
char* decryptage(char* r) {
char table[54]; 

// Our cipher table of 54 characters 
	table[0] = 'a';
	table[1] = 'b';
	table[2] = 'c';
	table[3] = 'd';
	table[4] = 'e';
	table[5] = 'f';    
	table[6] = 'g';
	table[7] = 'h';
	table[8] = 'i';
	table[9] = 'j';
	table[10] = 'k';   
	table[11] = 'l';
	table[12] = 'm';
	table[13] = 'n';
	table[14] = 'o';
	table[15] = 'p';    
	table[16] = 'q';
	table[17] = 'r';
	table[18] = 's';
	table[19] = 't';
	table[20] = 'u';   
	table[21] = 'v';
	table[22] = 'w';
	table[23] = 'x';
	table[24] = 'y';
	table[25] = 'z';   
	table[26] = '0';
	table[27] = '1';
	table[28] = '2';
	table[29] = '3';
	table[30] = '4';
	table[31] = '5';
	table[32] = '6';    
	table[33] = '7';
	table[34] = '8';
	table[35] = '9';
	table[36] = '.';
	table[37] = ',';   
	table[38] = '?';
	table[39] = '\'';
	table[40] = '!';
	table[41] = '/';
	table[42] = '(';    
	table[43] = ')';
	table[44] = '&';
	table[45] = ':';
	table[46] = ';';
	table[47] = '=';   
	table[48] = '+';
	table[49] = '-';
	table[50] = '_';
	table[51] = '\"';
	table[52] = '$';
	table[53] = '@';
	char * rep = malloc(strlen(r));

	// Decipher the whole string
	int i;
	for (i = 0; i < strlen(r); i++){
		rep[i]=table[defind(r[i],table)];
		
		
	}
	return rep;
}
