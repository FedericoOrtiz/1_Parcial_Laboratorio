#include <stdio.h>
#include <stdlib.h>
#include "Gets.h"
#include "Clientes_Mascotas.h"
#define TAM_C 10
#define TAM_M 20
#define TAM_R 10



int main()
{
    int opcion;
    int proximoIdMascota = 1011;
    int proximoIdCliente = 105;
    eCliente listaClientes[TAM_C];
    eMascota listaMascotas[TAM_M];
    eRaza listaRazas[TAM_R];

    inicializarClientes(listaClientes, TAM_C);
    inicializarMascotas(listaMascotas, TAM_M);
    hardcodearClientes(listaClientes, TAM_C);
    hardcodearMascotas(listaMascotas, TAM_M);

    do
    {
        printf("1. Mostrar DUENIOS\n"); //OK
        printf("2. Mostrar MASCOTAS\n"); //OK
        printf("3. Mostrar DUENIOS CON SUS RESPECTIVAS MASCOTAS\n"); //OK
        printf("4. Cargar MASCOTA\n");
        printf("5. Eliminar MASCOTA\n");
        printf("6. Modificar MASCOTA\n");
        printf("7. Cargar DUENIO\n");
        printf("8. Eliminar DUENIO\n");
        printf("9. Ordenar MASCOTAS POR TIPO\n");
        printf("10. Modificar DUENIO\n");
        printf("11. Mostrar DUENIOS CON MAS DE UNA MASCOTA\n");
        printf("12. Mostrar MASCOTAS DE MAS DE TRES ANIOS\n");
        printf("13. Mostrar MASCOTAS POR TIPO PARTICULAR\n");
        printf("14. Ordenar DUENIOS POR CANTIDAD DE MASCOTAS\n");
        printf("15. Ordenar DUENIOS POR CANTIDAD DE MASCOTAS Y POR ORDEN ALFABETICO\n");
        printf("16. Mostrar PROMEDIO DE EDAD ENTRE MASCOTAS\n");
        printf("17. Mostrar PROMEDIO DE EDAD ENTRE MASCOTAS POR TIPO\n");
        printf("18. Mostrar PORCENTAJE DE MUJERES SOBRE MIS CLIENTES\n");
        printf("19. Salir\n\n");
        opcion = getInt("Ingrese una opcion: ", "Error, ingrese una opcion: ", 2);
        system("cls");

        switch(opcion)
        {
            case 1:
                mostrarClientes(listaClientes, TAM_C);
                break;
            case 2:
                mostrarMascotas(listaMascotas, TAM_M, listaClientes, TAM_C);
                break;
            case 3:
                mostrarClientesConSusMascotas(listaClientes, TAM_C, listaMascotas, TAM_M);
                break;
            case 4:
                cargarMascotas(listaMascotas, TAM_M, listaClientes, TAM_C, proximoIdMascota);
                proximoIdMascota++;
                break;
            case 5:
                eliminarMascotas(listaMascotas, TAM_M, listaClientes, TAM_C);
                break;
            case 6:
                modificarMascotas(listaMascotas, TAM_M, listaClientes, TAM_C);
                break;
            case 7:
                cargarClientes(listaClientes, TAM_C, proximoIdCliente);
                proximoIdCliente++;
                break;
            case 8:
                eliminarClientes(listaClientes, TAM_C, listaMascotas, TAM_M);
                break;
            case 9:
                ordenarMascotasPorTipo(listaMascotas, TAM_M, listaClientes, TAM_C);
                break;
            case 10:
                modificarDuenios(listaClientes, TAM_C);
                break;
            case 11:
                mostrarClientesConMasDeUnaMascota(listaClientes, TAM_C, listaMascotas, TAM_M);
                break;
            case 12:
                mostrarMascotasMayoresDeTresAnios(listaMascotas, TAM_M, listaClientes, TAM_C);
                break;
            case 13:
                mostrarMascotasPorTipoElegido(listaMascotas, TAM_M, listaClientes, TAM_C);
                break;
            case 14:
                mostrarClientesPorCantidadDeMascotas(listaClientes,  TAM_C, listaMascotas, TAM_M);
                break;
            case 15:
                mostrarClientesPorCantidadDeMascotasYOrdenAlfabetico(listaClientes, TAM_C, listaMascotas, TAM_M);
                break;
            case 16:
                printf("Promedio de edad entre las mascotas: %.2f anios\n\n", promedioEdadMascotas(listaMascotas, TAM_M));
                break;
            case 17:
                promedioEdadMascotasPorTipo(listaMascotas, TAM_M);
                break;
            case 18:
                porcentajeMujeres(listaClientes, TAM_C);
                break;
            case 19:
                printf("Saliendo\n\n");
                break;
            default:
                printf("Ingrese una opcion valida\n\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion !=19);


    return 0;
}
