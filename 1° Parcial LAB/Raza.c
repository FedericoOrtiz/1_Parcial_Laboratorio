#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Raza.h"

/************************************** PUNTO 2 MODIFICACION **************************************/

void hardcodearRazas(eRaza listaRazas[], int tam)
{
    int id[15] = {0,1,2,3,4,5,6,7,8};
    int idTipo[15] = {1,1,1,2,2,2,3,3,3};
    char nombre[15][50] = {"Pitbull", "Labrador", "Bulldog","Siames", "Persa", "Chartreux" , "Iguana Verde", "Lagarto Overo", "Perico Monje"  };
    char pais[15][50] = {"EEUU", "Canada", "EEUU" , "Tailandia", "Iran", "Francia" , "America", "Argentina", "Argentina"  };

    for(int i=0; i<tam; i++)
    {
        listaRazas[i].id = id[i];
        listaRazas[i].idTipo = idTipo[i];
        strcpy(listaRazas[i].nombre, nombre[i]);
        strcpy(listaRazas[i].pais, pais[i]);
    }
}

void printR(eRaza listaRazas[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%s -- %s\n", listaRazas[i].nombre, listaRazas[i].pais);
    }
}
