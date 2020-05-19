#ifndef RAZA_H_INCLUDED
#define RAZA_H_INCLUDED

typedef struct
{
    int id;
    int idTipo; //1 perro 2 Gato 3 Raro
    char nombre[15];
    char pais[15];
}eRaza;

void hardcodearRazas(eRaza listaRazas[], int tam);
void printR(eRaza listaRazas[], int tam);


#endif // RAZA_H_INCLUDED
