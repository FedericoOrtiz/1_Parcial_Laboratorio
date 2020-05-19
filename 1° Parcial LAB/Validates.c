#include "Validates.h"

int validatesInt(char string[])
{
    int i = 0;
    int r = 1;
    while(string[i]!='\0')
    {
        if(string[0]=='\n' || string[i]==' ' && string[i]<'0' || string[i]>'9')
        {
            r = 0;
        }
        i++;
    }
    return r;
}

int validatesString(char string[])
{
    int i = 0;
    int r = 1;

    while(string[i] != '\0')
    {
        if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
        {
            r = 0;
        }
        i++;
    }
    return r;
}
