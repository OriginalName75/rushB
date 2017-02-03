#include "handleLED.h"
#include <unistd.h>

/*Manage the LED lighting according to the integer input
0 is space
2 is dot
3 is dash*/
void readInt(int e, int led){
  switch(e) {
  
    case 2 :
      write(led, 1, sizeof(int));
      usleep(TIME_DOT);//turn on the LED for the time associated with DOT
      write(led, 0, sizeof(int));
      usleep(TIME_DOT);//turn off the LED for the time associated with DOT
    break;
  
    case 3 :
      write(led, 1, sizeof(int));
      usleep(TIME_DASH);//turn on the LED for the time associated with DASH
      write(led, 0, sizeof(int));
      usleep(TIME_DOT);//turn off the LED for the time associated with DOT
    break;  
  
    default :
      write(led, 0, sizeof(int));
      usleep(TIME_SPACE);//turn off the LED for the time associated with SPACE
  
    }

}

/*Manage the LED lighting according to the integer array input*/
void readMorse(int* morse, int size, int led){
  int i;
  for (i=0; i < size; i++){
    readInt(morse[i], led);
  
  }

}
