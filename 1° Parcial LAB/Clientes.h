#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char localidad[20];
    char telefono[20];
    int edad;
    int estado;
    char sexo;
    int cantMascotas;
}eCliente;

void hardcodearClientes(eCliente listaClientes[], int tam);
void inicializarClientes(eCliente listaClientes[], int tam);
void mostrarClientes(eCliente listaClientes[], int tam);
int buscarLibreClientes(eCliente listaClientes[], int tam);
void cargarClientes(eCliente listaClientes[], int tam, int proximoIdCliente);
void modificarDuenios(eCliente listaClientes[], int tam);
void porcentajeMujeres(eCliente listaClientes[], int tam);


#endif // CLIENTES_H_INCLUDED
