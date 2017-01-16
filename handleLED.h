#pragma once
#include <unistd.h>
#include <time.h>
#define TIME_DOT 100
#define TIME_DASH 1000
#define TIME_SPACE 500


/*Manage the LED lighting according to the integer input
0 is space
2 is dot
3 is dash*/
void readInt(int e, int led);

/*Manage the LED lighting according to the integer array input*/
void readMorse(int* morse, int size, int led);

