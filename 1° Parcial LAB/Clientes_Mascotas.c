#include "Clientes_Mascotas.h"
#include "Gets.h"

/************************************** PUNTO 2 **************************************/
void mostrarMascotas(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes)
{
    int i;
    int j;
    eCliente auxCliente;

    printf("                    ***** LISTADO DE MASCOTAS *****\n\n");
    printf("    ID          Nombre  Tipo         Raza   Edad   Peso   Sexo                  Duenio\n\n");

    for(i=0; i<tamMascotas; i++)
    {
        if(listaMascotas[i].estado == 1)
        {
            for(j=0; j<tamClientes; j++)
            {
                if(listaMascotas[i].idDuenio == listaClientes[j].id && listaClientes[j].estado == 1)
                {
                    auxCliente = listaClientes[j];
                    break;
                }
            }

            printf("%6d %15s %5s %12s %6d %6.2f %6c %15s %15s\n", listaMascotas[i].id,
                                                                  listaMascotas[i].nombre,
                                                                  listaMascotas[i].tipo,
                                                                  listaMascotas[i].raza,
                                                                  listaMascotas[i].edad,
                                                                  listaMascotas[i].peso,
                                                                  listaMascotas[i].sexo,
                                                                  auxCliente.nombre,
                                                                  auxCliente.apellido);
        }

    }
    printf("\n");
}

/************************************** PUNTO 3 **************************************/
void mostrarClientesConSusMascotas(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas)
{
    int i;
    int j;

    printf("        ***** LISTADO DE DUENIOS CON SUS MASCOTAS *****\n\n");
    for(i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].estado == 1)
        {

        printf("         Nombre        Apellido        Telefono       Localidad    Edad    Sexo\n");
        printf("%15s %15s %15s %15s %7d %7c\n\n", listaClientes[i].nombre,
                                                      listaClientes[i].apellido,
                                                      listaClientes[i].telefono,
                                                      listaClientes[i].localidad,
                                                      listaClientes[i].edad,
                                                      listaClientes[i].sexo);


        printf("         Nombre  Tipo         Raza   Edad   Peso   Sexo\n");
        for(j=0;j<tamMascotas;j++)
        {
            if(listaMascotas[j].estado == 1 && listaClientes[i].id == listaMascotas[j].idDuenio)
            {

                printf("%15s %5s %12s %6d %6.2f %6c\n", listaMascotas[j].nombre,
                                                        listaMascotas[j].tipo,
                                                        listaMascotas[j].raza,
                                                        listaMascotas[j].edad,
                                                        listaMascotas[j].peso,
                                                        listaMascotas[j].sexo);
            }
        }
        printf("\n********************************************************************\n\n");
        }
    }
}

/************************************** PUNTO 4 **************************************/
void cargarMascotas(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes, int proximoIdMascota, eRaza listaRazas[], int tamRazas)
{
    eMascota auxMascota;
    int tipo;
    int index = buscarLibreMascotas(listaMascotas, tamMascotas);
    if(index != -1)
    {
        int flag = 1;
        int raza = -1;
        auxMascota.id = proximoIdMascota;

        printf("        ***** CARGAR MASCOTA *****\n\n");
        getString("Ingrese nombre: ", "Error, ingrese nombre: ", auxMascota.nombre);


        do
        {
            getString("Ingrese tipo (Perro/Gato/Raro): ", "Error, ingrese tipo: ", auxMascota.tipo);
        }while((strcmp(auxMascota.tipo, "Perro") != 0) && (strcmp(auxMascota.tipo, "Gato") != 0) && (strcmp(auxMascota.tipo, "Raro") != 0));

        if(strcmp(auxMascota.tipo, "Perro") == 0)
        {
            tipo = 1;
        }
        else if(strcmp(auxMascota.tipo, "Gato") == 0)
        {
            tipo = 2;
        }
        else if(strcmp(auxMascota.tipo, "Raro") == 0)
        {
            tipo = 3;
        }


            for(int i=0; i<tamRazas; i++)
            {
                switch(tipo)
                {
                case 1:
                    if(listaRazas[i].idTipo == 1)
                    {
                        printf("%d. %s -- %s\n", i,listaRazas[i].nombre, listaRazas[i].pais);
                    }
                    break;
                case 2:
                    if(listaRazas[i].idTipo == 2)
                    {
                        printf("%d. %s -- %s\n",  i,listaRazas[i].nombre, listaRazas[i].pais);
                    }
                    break;
                case 3:
                    if(listaRazas[i].idTipo == 3)
                    {
                        printf("%d. %s -- %s\n",  i,listaRazas[i].nombre, listaRazas[i].pais);
                    }
                    break;
                }
            }



        while(raza>9 || raza<0)
        {
            raza = getInt("Ingrese ID raza: ", "Error, ingrese ID raza", 2);
        }

        for(int i=0; i<tamRazas; i++)
        {
            if(raza == listaRazas[i].id)
            {
                strcpy(auxMascota.raza, listaRazas[i].nombre);
                break;
            }
        }

        auxMascota.edad = getInt("Ingrese edad: ", "Error, ingrese edad: ", 3);
        auxMascota.peso = getFloat("Ingrese peso: ");

        do
        {
            auxMascota.sexo = getChar("Ingrese sexo: ", "Error, ingrese sexo: ");
            auxMascota.sexo = toupper(auxMascota.sexo);
        }while(auxMascota.sexo != 'M' && auxMascota.sexo != 'F');

        mostrarClientes(listaClientes, tamClientes);


        while(flag)
        {
            auxMascota.idDuenio = getInt("Ingrese ID del duenio: ", "Error, ingrese ID del duenio: ", 4);
            for(int i=0; i<tamClientes; i++)
            {
                if(listaClientes[i].id == auxMascota.idDuenio)
                {
                    flag = 0;
                    listaClientes[i].cantMascotas++;
                    break;
                }
            }
        }

        auxMascota.estado = 1;
        listaMascotas[index] = auxMascota;
    }
    else
    {
        printf("Sistema Completo\n\n");
    }
}

/************************************** PUNTO 5 **************************************/
void eliminarMascotas(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes)
{
    printf("        ***** ELIMINAR MASCOTA *****\n\n");
    mostrarMascotas(listaMascotas, tamMascotas, listaClientes, tamClientes);
    char confirm = 'n';
    int flag = 1;
    while(flag)
    {
        int id = getInt("Ingrese ID de la mascota: ", "Error, ingrese ID de la mascota: ", 4);
            for(int i=0; i<tamMascotas; i++)
            {
                if(id == listaMascotas[i].id)
                {
                    flag = 0;
                    confirm = getChar("Confirma? (s/n): ", "Error, Confirma? (s/n): ");

                    if(confirm == 's' || confirm == 'S')
                    {
                        listaMascotas[i].estado = 0;
                        printf("\nMascota eliminada\n\n");
                    }
                    else
                    {
                        printf("\nOperacion cancelada\n\n");
                    }

                    for(int j=0; j<tamClientes; j++)
                    {
                        if(listaClientes[j].id == listaMascotas[i].idDuenio)
                        {
                            listaClientes[j].cantMascotas--;
                            break;
                        }
                    }
                    break;
                }
            }
    }

}


/************************************** PUNTO 6 **************************************/
void modificarMascotas(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes)
{
    printf("        ***** MODIFICAR MASCOTA *****\n\n");
    mostrarMascotas(listaMascotas, tamMascotas, listaClientes, tamClientes);

    int flag = 1;
    int flag2 = 1;

    while(flag)
    {
        int id = getInt("Ingrese ID de la mascota: ", "Error, ingrese ID de la mascota: ", 4);
        int option;
        for(int i=0; i<tamMascotas; i++)
        {
            if(id == listaMascotas[i].id)
            {
                flag = 0;
                do
                {
                    printf("\nQue desea modificar?\n");
                    printf("1. Nombre\n");
                    printf("2. Tipo\n");
                    printf("3. Raza\n");
                    printf("4. Edad\n");
                    printf("5. Peso\n");
                    printf("6. Sexo\n");
                    printf("7. Duenio\n");
                    printf("8. Volver al Menu\n\n");
                    option = getInt("Ingrese una opcion: ", "Error, ingrese una opcion: ", 2);
                    system("cls");

                    switch(option)
                    {
                    case 1:
                        getString("Reingrese nombre:", "Error, reingrese nombre: ", listaMascotas[i].nombre);
                        break;
                    case 2:
                        do
                        {
                            getString("Reingrese tipo (Perro/Gato/Raro): ", "Error, Reingrese tipo: ", listaMascotas[i].tipo);
                        }while((strcmp(listaMascotas[i].tipo, "Perro") != 0) && (strcmp(listaMascotas[i].tipo, "Gato") != 0) && (strcmp(listaMascotas[i].tipo, "Raro") != 0));
                        break;
                    case 3:
                        getString("Reingrese raza: ", "Error, Reingrese raza: ", listaMascotas[i].raza);
                        break;
                    case 4:
                        listaMascotas[i].edad = getInt("Reingrese edad: ", "Error, Reingrese edad: ", 4);
                        break;
                    case 5:
                        listaMascotas[i].peso = getFloat("Reingrese peso: ");
                        break;
                    case 6:
                        do
                        {
                            listaMascotas[i].sexo = getChar("Reingrese sexo: ", "Error, Reingrese sexo: ");
                            listaMascotas[i].sexo = toupper(listaMascotas[i].sexo);
                        }while(listaMascotas[i].sexo != 'M' && listaMascotas[i].sexo != 'F');
                        break;
                    case 7:
                        printf("                      ***** LISTADO DE DUENIOS *****\n\n");
                        printf("   ID          Nombre        Apellido        Telefono       Localidad    Edad    Sexo\n\n");
                        for(int i=0; i<tamClientes; i++)
                        {
                            if(listaClientes[i].estado == 1)
                            {
                                printf("%5d %15s %15s %15s %15s %7d %7c\n", listaClientes[i].id,
                                                                    listaClientes[i].nombre,
                                                                    listaClientes[i].apellido,
                                                                    listaClientes[i].telefono,
                                                                    listaClientes[i].localidad,
                                                                    listaClientes[i].edad,
                                                                    listaClientes[i].sexo);
                            }
                        }
                        printf("\n");
                        int idAssign;
                        while(flag2)
                        {
                            int idDuenio = getInt("Reingrese ID duenio: ", "Error, reingrese ID duenio: ", 4);

                            for(int i=0; i<tamClientes; i++)
                            {
                                if(idDuenio == listaClientes[i].id)
                                {
                                    flag2 = 0;
                                    idAssign = idDuenio;
                                    break;
                                }
                            }
                        }
                        listaMascotas[i].idDuenio = idAssign;
                        break;
                    case 8:
                        printf("Volviendo al Menu\n\n");
                        break;
                    default:
                        printf("Ingrese una opcion valida");
                        break;
                    }
                }while(option != 8);

                break;
            }
        }
    }
}

/************************************** PUNTO 8 **************************************/
void eliminarClientes(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas)
{
    printf("        ***** ELIMINAR DUENIO *****\n\n");
    mostrarClientes(listaClientes, tamClientes);
    int i;
    int j;
    char confirm = 'n';
    int flag = 1;

    while(flag)
    {
        int id = getInt("Ingrese ID del Duenio: ", "Error, ingrese ID del Duenio: ", 4);

        for(i=0; i<tamClientes; i++)
        {
            if(id == listaClientes[i].id)
            {
                flag = 0;
                confirm = getChar("Confirma? (s/n): ", "Error, Confirma? (s/n): ");
                if(confirm == 's' || confirm == 'S')
                {
                    listaClientes[i].estado = 0;
                    for(j=0; j<tamMascotas; j++)
                    {
                        if(listaClientes[i].id == listaMascotas[j].idDuenio)
                        {
                            listaMascotas[j].estado = 0;
                        }
                    }
                    printf("\nDuenio eliminado\n\n");
                }
                else
                {
                    printf("\nOperacion cancelada\n\n");
                }
                break;
            }
        }
    }
}

/************************************** PUNTO 9 **************************************/
void ordenarMascotasPorTipo(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes)
{
    eMascota auxMascota;
    eCliente auxCliente;

    int i;
    int j;
    for(i=0; i<tamMascotas-1; i++)
    {
        for(j=i+1; j<tamMascotas; j++)
        {
            if(strcmp(listaMascotas[i].tipo, listaMascotas[j].tipo) > 0)
                {
                    auxMascota = listaMascotas[i];
                    listaMascotas[i] = listaMascotas[j];
                    listaMascotas[j] = auxMascota;
                }
        }
    }

    printf("                    ***** LISTADO DE MASCOTAS POR TIPO*****\n\n");
    printf("    ID          Nombre  Tipo         Raza   Edad   Peso   Sexo                  Duenio\n\n");

    for(i=0; i<tamMascotas; i++)
    {
        if(listaMascotas[i].estado == 1)
        {
            for(j=0; j<tamClientes; j++)
            {
                if(listaClientes[j].estado == 1 && listaMascotas[i].idDuenio == listaClientes[j].id)
                {
                    auxCliente = listaClientes[j];
                    break;
                }
            }

            printf("%6d %15s %5s %12s %6d %6.2f %6c %15s %15s\n", listaMascotas[i].id,
                                                                  listaMascotas[i].nombre,
                                                                  listaMascotas[i].tipo,
                                                                  listaMascotas[i].raza,
                                                                  listaMascotas[i].edad,
                                                                  listaMascotas[i].peso,
                                                                  listaMascotas[i].sexo,
                                                                  auxCliente.nombre,
                                                                  auxCliente.apellido);

        }
    }
    printf("\n");
}

/************************************** PUNTO 11 **************************************/
void mostrarClientesConMasDeUnaMascota(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas)
{
    printf("                      ***** LISTADO DE DUENIOS CON MAS DE UNA MASCOTA*****\n");


    for(int i=0; i<tamClientes; i++)
    {
        int acumMascotas = 0;

        for(int j=0; j<tamMascotas ;j++)
        {
            if(listaClientes[i].estado == 1 && listaClientes[i].id == listaMascotas[j].idDuenio)
            {
                acumMascotas++;
            }
        }

        if(acumMascotas>1)
        {
            {
                printf("\n   ID          Nombre        Apellido        Telefono       Localidad    Edad    Sexo\n");
                printf("%5d %15s %15s %15s %15s %7d %7c\n\n", listaClientes[i].id,
                                                            listaClientes[i].nombre,
                                                            listaClientes[i].apellido,
                                                            listaClientes[i].telefono,
                                                            listaClientes[i].localidad,
                                                            listaClientes[i].edad,
                                                            listaClientes[i].sexo);
            }

            printf("         Nombre  Tipo         Raza   Edad   Peso   Sexo\n");
            for(int j=0; j<tamMascotas; j++)
            {
                if(listaMascotas[j].idDuenio == listaClientes[i].id && listaMascotas[j].estado == 1)
                {
                   printf("%15s %5s %12s %6d %6.2f %6c\n", listaMascotas[j].nombre,
                                                               listaMascotas[j].tipo,
                                                               listaMascotas[j].raza,
                                                               listaMascotas[j].edad,
                                                               listaMascotas[j].peso,
                                                               listaMascotas[j].sexo);
                }
            }


        }
    }
    printf("\n");
}

/************************************** PUNTO 12 **************************************/
void mostrarMascotasMayoresDeTresAnios(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes)
{
    eCliente auxCliente;
    printf("                      ***** LISTADO DE MASCOTAS MAYORES DE 3 ANIOS*****\n\n");


    for(int i=0; i<tamMascotas; i++)
    {
        printf("    ID          Nombre  Tipo         Raza   Edad   Peso   Sexo                  Duenio\n\n");
        if(listaMascotas[i].edad > 3 && listaMascotas[i].estado == 1)
        {
            for(int j=0; j<tamClientes; j++)
            {
                if(listaMascotas[i].idDuenio == listaClientes[j].id && listaClientes[j].estado == 1)
                {
                    auxCliente = listaClientes[j];
                    break;
                }
            }

            printf("%6d %15s %5s %12s %6d %6.2f %6c %15s %15s\n", listaMascotas[i].id,
                                                                  listaMascotas[i].nombre,
                                                                  listaMascotas[i].tipo,
                                                                  listaMascotas[i].raza,
                                                                  listaMascotas[i].edad,
                                                                  listaMascotas[i].peso,
                                                                  listaMascotas[i].sexo,
                                                                  auxCliente.nombre,
                                                                  auxCliente.apellido);
        }
    }
    printf("\n");
}

/************************************** PUNTO 13 **************************************/
void mostrarMascotasPorTipoElegido(eMascota listaMascotas[], int tamMascotas, eCliente listaClientes[], int tamClientes)
{
    eCliente auxCliente;
    int opcion;
    printf("1. Perro\n2. Gato\n3. Raro\n");
    do
    {
        opcion = getInt("Ingrese tipo de mascota: ", "Error, ingrese tipo de mascota: ", 1);
    }while(opcion > 3 || opcion < 1);
    system("cls");


    printf("                      ***** LISTADO DE MASCOTAS POR TIPO ELEGIDO*****\n\n");
    printf("    ID          Nombre  Tipo         Raza   Edad   Peso   Sexo                  Duenio\n\n");

    for(int i=0; i<tamMascotas; i++)
    {
        switch(opcion)
        {
            case 1:
                if(strcmp(listaMascotas[i].tipo, "Perro") == 0 && listaMascotas[i].estado == 1)
                {
                    for(int j=0; j<tamClientes; j++)
                    {
                        if(listaMascotas[i].idDuenio == listaClientes[j].id && listaClientes[j].estado == 1)
                        {
                            auxCliente = listaClientes[j];
                            break;
                        }
                    }

                    printf("%6d %15s %5s %12s %6d %6.2f %6c %15s %15s\n", listaMascotas[i].id,
                                                                          listaMascotas[i].nombre,
                                                                          listaMascotas[i].tipo,
                                                                          listaMascotas[i].raza,
                                                                          listaMascotas[i].edad,
                                                                          listaMascotas[i].peso,
                                                                          listaMascotas[i].sexo,
                                                                          auxCliente.nombre,
                                                                          auxCliente.apellido);
                }
                break;
            case 2:
                if(strcmp(listaMascotas[i].tipo, "Gato") == 0 && listaMascotas[i].estado == 1)
                {
                    for(int j=0; j<tamClientes; j++)
                    {
                        if(listaMascotas[i].idDuenio == listaClientes[j].id && listaClientes[j].estado == 1)
                        {
                            auxCliente = listaClientes[j];
                            break;
                        }
                    }

                    printf("%6d %15s %5s %12s %6d %6.2f %6c %15s %15s\n", listaMascotas[i].id,
                                                                          listaMascotas[i].nombre,
                                                                          listaMascotas[i].tipo,
                                                                          listaMascotas[i].raza,
                                                                          listaMascotas[i].edad,
                                                                          listaMascotas[i].peso,
                                                                          listaMascotas[i].sexo,
                                                                          auxCliente.nombre,
                                                                          auxCliente.apellido);
                }
                break;
            case 3:
                if(strcmp(listaMascotas[i].tipo, "Raro") == 0 && listaMascotas[i].estado == 1)
                {
                    for(int j=0; j<tamClientes; j++)
                    {
                        if(listaMascotas[i].idDuenio == listaClientes[j].id && listaClientes[j].estado == 1)
                        {
                            auxCliente = listaClientes[j];
                            break;
                        }
                    }

                    printf("%6d %15s %5s %12s %6d %6.2f %6c %15s %15s\n", listaMascotas[i].id,
                                                                          listaMascotas[i].nombre,
                                                                          listaMascotas[i].tipo,
                                                                          listaMascotas[i].raza,
                                                                          listaMascotas[i].edad,
                                                                          listaMascotas[i].peso,
                                                                          listaMascotas[i].sexo,
                                                                          auxCliente.nombre,
                                                                          auxCliente.apellido);
                }
                break;
        }
    }
    printf("\n");
}

/************************************** PUNTO 14 **************************************/
void mostrarClientesPorCantidadDeMascotas(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas)
{
    printf("                      ***** LISTADO DE DUENIOS POR CANTIDAD DE MASCOTAS*****\n");

    eCliente auxCliente;
    int i;
    int j;
    for(i=0; i<tamClientes-1; i++)
    {
        for(j=i+1; j<tamClientes; j++)
        {
            if((listaClientes[i].cantMascotas > listaClientes[j].cantMascotas) && (listaClientes[i].estado == 1 && listaClientes[j].estado == 1))
            {
                auxCliente = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = auxCliente;
            }
        }
    }

    for(i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].estado == 1)
        {

        printf("         Nombre        Apellido        Telefono       Localidad    Edad    Sexo\n");
        printf("%15s %15s %15s %15s %7d %7c\n\n", listaClientes[i].nombre,
                                                      listaClientes[i].apellido,
                                                      listaClientes[i].telefono,
                                                      listaClientes[i].localidad,
                                                      listaClientes[i].edad,
                                                      listaClientes[i].sexo);


        printf("         Nombre  Tipo         Raza   Edad   Peso   Sexo\n");
        for(j=0;j<tamMascotas;j++)
        {
            if(listaMascotas[j].estado == 1 && listaClientes[i].id == listaMascotas[j].idDuenio)
            {

                printf("%15s %5s %12s %6d %6.2f %6c\n", listaMascotas[j].nombre,
                                                        listaMascotas[j].tipo,
                                                        listaMascotas[j].raza,
                                                        listaMascotas[j].edad,
                                                        listaMascotas[j].peso,
                                                        listaMascotas[j].sexo);
            }
        }
        printf("\n********************************************************************\n\n");
        }
    }
}

/************************************** PUNTO 15 **************************************/
void mostrarClientesPorCantidadDeMascotasYOrdenAlfabetico(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas)
{
    printf("                      ***** LISTADO DE DUENIOS POR CANTIDAD DE MASCOTAS Y POR ORDEN ALFABETICO*****\n");

    eCliente auxCliente;
    int i;
    int j;
    for(i=0; i<tamClientes-1; i++)
    {
        for(j=i+1; j<tamClientes; j++)
        {
            if((listaClientes[i].cantMascotas > listaClientes[j].cantMascotas) && (listaClientes[i].estado == 1 && listaClientes[j].estado == 1))
            {
                auxCliente = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = auxCliente;
            }
            else if((listaClientes[i].cantMascotas == listaClientes[j].cantMascotas) && (listaClientes[i].estado == 1 && listaClientes[j].estado == 1) && (strcmp(listaClientes[i].nombre, listaClientes[j].nombre) > 0))
            {
                auxCliente = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = auxCliente;
            }
        }
    }

    for(i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].estado == 1)
        {

        printf("         Nombre        Apellido        Telefono       Localidad    Edad    Sexo\n");
        printf("%15s %15s %15s %15s %7d %7c\n\n", listaClientes[i].nombre,
                                                      listaClientes[i].apellido,
                                                      listaClientes[i].telefono,
                                                      listaClientes[i].localidad,
                                                      listaClientes[i].edad,
                                                      listaClientes[i].sexo);


        printf("         Nombre  Tipo         Raza   Edad   Peso   Sexo\n");
        for(j=0;j<tamMascotas;j++)
        {
            if(listaMascotas[j].estado == 1 && listaClientes[i].id == listaMascotas[j].idDuenio)
            {

                printf("%15s %5s %12s %6d %6.2f %6c\n", listaMascotas[j].nombre,
                                                        listaMascotas[j].tipo,
                                                        listaMascotas[j].raza,
                                                        listaMascotas[j].edad,
                                                        listaMascotas[j].peso,
                                                        listaMascotas[j].sexo);
            }
        }
        printf("\n********************************************************************\n\n");
        }
    }
}
/************************************** PUNTO 19 **************************************/
void mostrarClientesConMascotasMismoSexo(eCliente listaClientes[], int tamClientes, eMascota listaMascotas[], int tamMascotas)
{
    printf("                      ***** LISTADO DE DUENIOS CON MASCOTAS DEL MISMO SEXO*****\n\n");
    int i;
    int j;
    for(i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].estado == 1)
        {
            printf("         Nombre        Apellido        Telefono       Localidad    Edad    Sexo\n");
            printf("%15s %15s %15s %15s %7d %7c\n\n", listaClientes[i].nombre,
                                                          listaClientes[i].apellido,
                                                          listaClientes[i].telefono,
                                                          listaClientes[i].localidad,
                                                          listaClientes[i].edad,
                                                          listaClientes[i].sexo);
            printf("         Nombre  Tipo         Raza   Edad   Peso   Sexo\n");

            for(j=0; j<tamMascotas-1; j++)
            {
                    if(listaMascotas[j].estado == 1 && listaMascotas[j+1].estado == 1 &&
                       listaMascotas[j].idDuenio == listaClientes[i].id && listaMascotas[j+1].idDuenio == listaClientes[i].id &&
                       listaMascotas[j].sexo == listaMascotas[j+1].sexo)
                        {
                        printf("%15s %5s %12s %6d %6.2f %6c\n", listaMascotas[j].nombre,
                                                            listaMascotas[j].tipo,
                                                            listaMascotas[j].raza,
                                                            listaMascotas[j].edad,
                                                            listaMascotas[j].peso,
                                                            listaMascotas[j].sexo);
                        }

            }
            printf("\n********************************************************************\n\n");
        }

    }
    printf("\n");
}
