#include "Clientes.h"

void hardcodearClientes(eCliente listaClientes[], int tam)
{
    int id[10]= {100,101,102,103,104};
    char nombre[10][20]= {"Marta","Jose","Lucia","Juan","Ernesto"}; //Marta: mujer -- Jose: señor -- Lucia: chica -- Juan: chico -- Ernesto: señor2
    char apellido[10][51]= {"Nogueira","Alperovich","Gomez","Gonzalez","Gainza"};
    char localidad[10][51]= {"Belgrano","Liniers","Caballito","Colegiales","Villa Urquiza"};
    char telefono[10][51]= {"4123-3214","4789-6547","4321-6548","4987-3254","4971-6491"};
    int edad[10]= {50,70,20,25,60};
    char sexo[10]= {'F','M','F','M','M'};
    int estado[10]= {1,1,1,1,1};
    int cantMascotas[10] = {2,3,2,1,3};

    for(int i=0; i<tam; i++)
    {
        listaClientes[i].id = id[i];
        listaClientes[i].edad = edad[i];
        listaClientes[i].sexo = sexo[i];
        listaClientes[i].estado = estado[i];
        strcpy(listaClientes[i].nombre,nombre[i]);
        strcpy(listaClientes[i].apellido,apellido[i]);
        strcpy(listaClientes[i].localidad,localidad[i]);
        strcpy(listaClientes[i].telefono,telefono[i]);
        listaClientes[i].cantMascotas = cantMascotas[i];
    }
}

void inicializarClientes(eCliente listaClientes[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        listaClientes[i].estado= 0;
    }
}

int buscarLibreClientes(eCliente listaClientes[], int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if(listaClientes[i].estado == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}

/************************************** PUNTO 1 **************************************/
void mostrarClientes(eCliente listaClientes[], int tam)
{
    printf("                      ***** LISTADO DE DUENIOS *****\n\n");
    printf("   ID          Nombre        Apellido        Telefono       Localidad    Edad    Sexo\n\n");
    for(int i=0; i<tam; i++)
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
}

/************************************** PUNTO 7 **************************************/
void cargarClientes(eCliente listaClientes[], int tam, int proximoIdCliente)
{
    eCliente auxCliente;
    int index = buscarLibreClientes(listaClientes, tam);

    if(index != -1)
    {
        auxCliente.id = proximoIdCliente;
        auxCliente.estado = 1;

        printf("        ***** CARGAR DUENIO *****\n\n");
        getString("Ingrese nombre: ", "Error, ingrese nombre: ", auxCliente.nombre);
        getString("Ingrese apellido: ", "Error, ingrese apellido: ", auxCliente.apellido);
        getString("Ingrese localidad: ", "Error, ingrese localidad: ", auxCliente.localidad);
        printf("Ingrese telefono: ");
        scanf("%s", auxCliente.telefono);
        auxCliente.edad = getInt("Ingrese edad: ", "Error, ingrese edad: ", 3);

        do
        {
            auxCliente.sexo = getChar("Ingrese sexo: ", "Error, ingrese sexo: ");
            auxCliente.sexo = toupper(auxCliente.sexo);
        }while(auxCliente.sexo != 'M' && auxCliente.sexo != 'F');
        auxCliente.cantMascotas = 0;

        listaClientes[index] = auxCliente;
    }
    else
    {
        printf("Sistema Completo\n\n");
    }
}

/************************************** PUNTO 10 **************************************/
void modificarDuenios(eCliente listaClientes[], int tam)
{
    printf("        ***** MODIFICAR DUENIO *****\n\n");
    mostrarClientes(listaClientes, tam);

    int flag = 1;

    while(flag)
    {
        int id = getInt("Ingrese ID del Duenio: ", "Error, ingrese ID del Duenio: ", 4);
        int option;

        for(int i=0; i<tam; i++)
        {
            if(id == listaClientes[i].id)
            {
                flag = 0;
                do
                {
                    printf("\nQue desea modificar?\n");
                    printf("1. Nombre\n");
                    printf("2. Apellido\n");
                    printf("3. Localidad\n");
                    printf("4. Telefono\n");
                    printf("5. Edad\n");
                    printf("6. Sexo\n");
                    printf("7. Volver al Menu\n\n");
                    option = getInt("Ingrese una opcion: ", "Error, ingrese una opcion", 1);
                    system("cls");

                    switch(option)
                    {
                    case 1:
                        getString("Reingrese nombre:", "Error, reingrese nombre: ", listaClientes[i].nombre);
                        break;
                    case 2:
                        getString("Reingrese apellido: ", "Reingrese, ingrese apellido: ", listaClientes[i].apellido);
                        break;
                    case 3:
                        getString("Reingrese localidad: ", "Error, Reingrese localidad: ", listaClientes[i].localidad);
                        break;
                    case 4:
                        printf("Ingrese telefono: ");
                        scanf("%s", listaClientes[i].telefono);
                        break;
                    case 5:
                        listaClientes[i].edad = getInt("Reingrese edad: ", "Error, Reingrese edad: ", 4);
                        break;
                    case 6:
                        do
                        {
                            listaClientes[i].sexo = getChar("Reingrese sexo: ", "Error, Reingrese sexo: ");
                            listaClientes[i].sexo = toupper(listaClientes[i].sexo);
                        }while(listaClientes[i].sexo != 'M' && listaClientes[i].sexo != 'F');
                        break;
                    case 7:
                        printf("Volviendo al Menu\n\n");
                        break;
                    default:
                        printf("Ingrese una opcion valida");
                        break;
                    }
                }while(option != 7);

                break;
            }
        }

    }

}

/************************************** PUNTO 18 **************************************/
void porcentajeMujeres(eCliente listaClientes[], int tam)
{
    int cantM = 0;
    int total = 0;
    float porcMujeres;

    for(int i=0; i<tam; i++)
    {
        if(listaClientes[i].estado == 1)
        {
            if(listaClientes[i].sexo == 'F')
            {
                cantM++;
            }
            total++;
        }
    }

    porcMujeres = ((float)cantM/total)*100;

    printf("Porcentaje de clientes mujeres: %.2f\n\n", porcMujeres);
}
