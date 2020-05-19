#ifndef CLIENTES_MASCOTAS_H_INCLUDED
#define CLIENTES_MASCOTAS_H_INCLUDED
#include "Clientes.h"
#include "Mascotas.h"

void mostrarClientesConSusMascotas(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas);
void mostrarMascotas(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes);
void cargarMascotas(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes, int proximoIdMascota, eRaza listaRazas[], int tamRazas);
void eliminarMascotas(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes);
void modificarMascotas(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes);
void eliminarClientes(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas);
void ordenarMascotasPorTipo(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes);
void mostrarClientesConMasDeUnaMascota(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas);
void mostrarMascotasMayoresDeTresAnios(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes);
void mostrarMascotasPorTipoElegido(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes);
void mostrarClientesPorCantidadDeMascotas(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas);
void mostrarClientesPorCantidadDeMascotasYOrdenAlfabetico(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas);
void mostrarClientesConMascotasMismoSexo(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas);

#endif // CLIENTES_MASCOTAS_H_INCLUDED
