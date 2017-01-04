/*convertit char c en un caractere out conforme a l'alphabet simplifie.
Renvoie 2 si le caractere c est special, 1 si c'est une majuscule et 0 s'il est déja conforme. */
int transChar(char c, char* out);

/*convertit le string s en un string out conforme a l'alphabet simplifie.
Renvoie 1 si le texte out est different de s, 0 sinon.*/
int transString(char* s, char* out);
