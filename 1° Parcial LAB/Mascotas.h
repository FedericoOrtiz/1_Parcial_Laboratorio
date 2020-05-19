#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Raza.h"
#include "Gets.h"

typedef struct
{
    int id;
    int idDuenio;
    char nombre[20];
    char tipo[20];
    char raza[20];
    int edad;
    float peso;
    char sexo;
    int estado;
    int idRaza;
}eMascota;

void inicializarMascotas(eMascota listaMascotas[], int tam);
void hardcodearMascotas(eMascota listaMascotas[], int tam);
int buscarLibreMascotas(eMascota listaMascotas[], int tam);
float promedioEdadMascotas(eMascota listaMascotas[], int tam);
void promedioEdadMascotasPorTipo(eMascota listaMascotas[], int tam);

#endif // MASCOTAS_H_INCLUDED
