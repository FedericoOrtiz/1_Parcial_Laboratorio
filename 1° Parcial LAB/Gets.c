#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include "Validates.h"

int getInt(char message[], char error[], int len)
{
    int num;
    char auxNum[len];

    printf("%s", message);
    fflush(stdin);
    gets(auxNum);

    while(validatesInt(auxNum) != 1 || auxNum[0] == '\0')
    {
        printf("%s", error);
        fflush(stdin);
        gets(auxNum);
    }

    num = atoi(auxNum);

    return num;
}

float getFloat(char message[])
{
    float num;

    printf("%s", message);
    scanf("%f",&num);

    return num;

}

char getChar(char message[], char error[])
{
    char letter;

    printf("%s", message);
    fflush(stdin);
    scanf("%c",&letter);

    while((letter < 'a' || letter > 'z') && (letter < 'A' || letter > 'Z'))
    {
        printf("%s", error);
        fflush(stdin);
        scanf("%c",&letter);
    }

    return letter;
}

void getString(char message[], char error[], char input[])
{
    printf("%s", message);
    fflush(stdin);
    gets(input);

    while(validatesString(input) != 1 || input[0] == '\0' || input[0] == ' ' || (strlen(input)<3))
    {
        printf("%s", error);
        fflush(stdin);
        gets(input);
    }
}

