#include <handleLED.h>

/*Gere le clignotement de la led en morse selon l'entier en input
0 est un espace en morse
2 est un point en morse
3 est un trait en morse*/
void readInt(int e, int led){
  switch(e) {
  
    case 2 :
      write(led, 1, sizeof(int));
      sleep(TIME_DOT);//s'allume pendant le temps d'un point
      write(led, 0, sizeof(int));
      sleep(TIME_DOT);//s'eteint pendant le temps d'un point
    break;
  
    case 3 :
      write(led, 1, sizeof(int));
      sleep(TIME_DASH);//s'allume pendant le temps d'un trait
      write(led, 0, sizeof(int));
      sleep(TIME_DOT);//s'eteint pendant le temps d'un point
    break;  
  
    default :
      write(led, 0, sizeof(int));
      sleep(TIME_SPACE);//reste eteint le temps d'un espace
  
    }

}

/*Gere le clignotement de la led en morse pour un tableau d'entier morse en input*/
void readMorse(int* morse, int size, int led){
  int i;
  for (i=0; i < size; i++){
    readInt(morse[i]);
  
  }

}
