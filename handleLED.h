#pragma once
#include <unistd.h>
#include <time.h>
#define TIME_DOT 100
#define TIME_DASH 1000
#define TIME_SPACE 500


/*Gere le clignotement de la led en morse selon l'entier en input
0 est un espace en morse
2 est un point en morse
3 est un trait en morse*/
void readInt(int e, int led);

/*Gere le clignotement de la led en morse pour un tableau d'entier morse en input*/
void readMorse(int* morse, int size, int led);

