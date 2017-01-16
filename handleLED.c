#include <handleLED.h>

void readInt(int e, int led){
  switch(e) {
  
    case 2 :
      write(led, 1, sizeof(int));
      sleep(TIME_DOT);
      write(led, 0, sizeof(int));
      sleep(TIME_DOT);
    break;
  
    case 3 :
      write(led, 1, sizeof(int));
      sleep(TIME_DASH);
      write(led, 0, sizeof(int));
      sleep(TIME_DOT);
    break;  
  
    default :
      write(led, 0, sizeof(int));
      sleep(TIME_SPACE);
  
    }

}

void readMorse(int* morse, int size, int led){
  int i;
  for (i=0; i < size; i++){
    readInt(morse[i]);
  
  }

}
