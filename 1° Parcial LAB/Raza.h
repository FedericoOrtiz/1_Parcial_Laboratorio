#ifndef RAZA_H_INCLUDED
#define RAZA_H_INCLUDED

typedef struct
{
    char nombre[3];
    char pais[3];
}eRaza;

void inicializarRazas(eRaza listaRazas[], int tam);
void hardcodearRazas(eRaza listaRazas[], int tam);


#endif // RAZA_H_INCLUDED
