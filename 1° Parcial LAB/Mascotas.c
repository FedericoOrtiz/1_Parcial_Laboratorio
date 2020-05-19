#include "Mascotas.h"

void inicializarMascotas(eMascota listaMascotas[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        listaMascotas[i].estado = 0;
    }
}


void hardcodearMascotas(eMascota listaMascotas[], int tam)
{
    int id[20]= {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
    int idCliente[20]= {100,100,101,101,101,102,102,103,104,104,104};
    char nombre[20][51]= {"Gata1","Gata2","Perro1","Perro2","Gato3","Perro4","Iguana1","Perro5","Gato4","Gato5","Perro5"};
    char tipo[20][51]= {"Gato","Gato","Perro","Perro","Gato","Perro","Raro","Perro","Gato","Gato","Perro"};
    char raza[20][51]= {"Siames","Siames","Mestizo","Mestizo","Siames","Pitbull","Verde","Labrador","Mestizo","Mestizo","Bulldog"};
    int edad[20]= {5,5,3,7,6,4,2,6,3,3,10};
    float peso[20]= {4.3,4.4,30.5,29.5,5.4,38.7,3.2,30.2,6.3,4.1,20.5};
    char sexo[20]= {'F','F','M','M','M','M','F','M','M','M','M'};
    int estado[20]= {1,1,1,1,1,1,1,1,1,1,1};

    for(int i=0; i<tam; i++)
    {
        listaMascotas[i].id = id[i];
        listaMascotas[i].idDuenio = idCliente[i];
        listaMascotas[i].edad = edad[i];
        listaMascotas[i].peso = peso[i];
        listaMascotas[i].sexo = sexo[i];
        listaMascotas[i].estado = estado[i];
        strcpy(listaMascotas[i].tipo,tipo[i]);
        strcpy(listaMascotas[i].raza,raza[i]);
        strcpy(listaMascotas[i].nombre,nombre[i]);
    }
}

int buscarLibreMascotas(eMascota listaMascotas[], int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if(listaMascotas[i].estado == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}
/************************************** PUNTO 16 **************************************/
float promedioEdadMascotas(eMascota listaMascotas[], int tam)
{
    int acumEdad = 0;
    int cantMascotas = 0;
    float promedio;

    for(int i=0; i<tam; i++)
    {
        if(listaMascotas[i].estado == 1)
        {
            acumEdad = acumEdad + listaMascotas[i].edad;
            cantMascotas++;
        }
    }

    promedio = (float)acumEdad/cantMascotas;

    return promedio;
}

/************************************** PUNTO 17 **************************************/
void promedioEdadMascotasPorTipo(eMascota listaMascotas[], int tam)
{
    //posicion 0 -> acumEdad    posicion 1 -> cantMascotas
    int acumEdadPerros = 0;
    int cantPerros = 0;
    int acumEdadGatos = 0;
    int cantGatos = 0;
    int acumEdadRaros= 0;
    int cantRaros = 0;
    float promPerros;
    float promGatos;
    float promRaros;

    for(int i=0; i<tam; i++)
    {
        if(listaMascotas[i].estado == 1)
        {
            if(strcmp(listaMascotas[i].tipo, "Perro") == 0)
            {
                acumEdadPerros = acumEdadPerros + listaMascotas[i].edad;
                cantPerros++;
            }
            else if(strcmp(listaMascotas[i].tipo, "Gato") == 0)
            {
                acumEdadGatos = acumEdadGatos + listaMascotas[i].edad;
                cantGatos++;
            }
            else if(strcmp(listaMascotas[i].tipo, "Raro") == 0)
            {
                acumEdadRaros = acumEdadRaros + listaMascotas[i].edad;
                cantRaros++;
            }
        }
    }

    promPerros = (float)acumEdadPerros/cantPerros;
    promGatos = (float)acumEdadGatos/cantGatos;
    promRaros = (float)acumEdadRaros/cantRaros;


    printf("Promedio de edad entre perros: %.2f anios\n", promPerros);
    printf("Promedio de edad entre gatos: %.2f anios\n", promGatos);
    printf("Promedio de edad entre raros: %.2f anios\n\n", promRaros);
}
