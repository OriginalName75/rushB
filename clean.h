/*converting char c to char out in a simplified alphabet. 
Return 2 if c is special, 1 if c is a capital letter et 0 if c is in the simplified alphabet. */
int transChar(char c, char* out);

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
int transString(char* s, char* out);
