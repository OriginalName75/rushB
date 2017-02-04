# rushB

Product owner :
Aubertot Quentin

Scrum master :
Sun Tithnara

Technicians :
Babidi 'Jhen' Moran |
Zhu Lei |
Welte Anthony

OBJECTIF :
  Le but de notre projet est d'envoyer un message depuis un ordinateur sur une carte. Afin de protéger le message, on effectue un codage avant l'envoi puis un décodage lors de la réception du message. Le message est un texte qui sera transformé en morse. Pour cela, on simplifiera d'abord le message de base afin de supprimer certains caractères spéciaux. Ensuite on effectue le codage puis enfin la transformation en "morse". Afin de pouvoir décoder le morse en sortie, on transmet le message dans un binaire différent du morse. Sur la carte, on peut utiliser une led pour afficher le message en morse codé. On peut aussi décoder le message pour retrouver le message simplifié (en ne peut pas retrouver le message exact d'entré s'il y avait des caractères spéciaux. 

OBJECTIVE:
  The goal of this project is to send a message from a computer to an APF28 Armadeus card. In order to protect our message, we use the Cesar Cipher. (+3) The message is a text transformed into Morse. First the message is simplified, then it is ciphered, then it is turned into Morse. On the card, the LED can show the Morse code. The message can also be deciphered.

# Installation
* Compile the three programs
* Put server.out and led.out in the home directory on the board
* Put startup.sh in the /etc/init.d directory and make sure it is executable
* Reboot the board
* Once the board has rebooted the programs should have launched automatically
* launch client.out on our local machine and specify the board ip address in argument
* Type

# Local test
The script test_local.sh can be used to test the system on a single machine. It requires xterm to be installed.
Three terminals are launched, you can interact with the client and watch the result in the other terminals.


# Simple example of cryptography and morse

char* entre = "t*est";
char sortie[42];

transString(entre,sortie); // remove unusual characteres
>> "test"

char* sortie2=cryptage(sortie); // use cesar
>> "whvw"

long aaa = stringToMorse(sortie2); // convert to morse
>> 13652452657 // 0b1100101101101111111110010100110001

int* size=(int*) malloc(sizeof(int));
long* rep = binaryToMorse(aaa, size);

char* rep2 = binaryToMorseChar(rep, *size); // morse to string
>> "whvw"

char* rep22 = decryptage(rep2); // decipher with cesar
>> "test"
