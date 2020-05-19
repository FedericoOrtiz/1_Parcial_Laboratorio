#ifndef GETS_H_INCLUDED
#define GETS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getInt(char message[], char error[], int len);
float getFloat(char message[]);
char getChar(char message[], char error[]);
void getString(char message[], char error[], char input[]);

#endif // GETS_H_INCLUDED
