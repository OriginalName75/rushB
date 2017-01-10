#pragma once
#include <unistd.h>
#include <time.h>
#define TIME_DOT 100
#define TIME_DASH 1000
#define TIME_SPACE 500



void readInt(int e, int led);
void readMorse(int* morse, int size, int led);

