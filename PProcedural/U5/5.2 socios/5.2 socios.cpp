#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int DNI;
    int edad;
    char estado[10];
    char tipos;
} Socio;

Socio *cargaSocios(int N)
{

    int i;
    Socio *arre = (Socio *)malloc(N * (sizeof(Socio)));

    if (arre == NULL)
    {
        printf("No se pudo crear el arreglo\n");
    }
    else
    {
        printf("----- Carga de socios -----\n");
        for (i = 0; i < N; i++)
        {
            printf("Ingrese DNI del socio: ");
            scanf("%d", &arre[i].DNI);
            while (getchar() != '\n')
                ;
            printf("Ingrese edad del socio: ");
            scanf("%d", &arre[i].edad);
            while (getchar() != '\n')
                ;
            printf("Ingese tipo de socio ('A': Socio deportivo, 'J': Socio Jubilado): ");
            scanf("%c", &arre[i].tipos);
            while (getchar() != '\n')
                ;
            printf("Ingrese estado del socio (Activo o Inactivo): ");
            scanf("%s", &arre[i].estado);
            while (getchar() != '\n')
                ;
        }
        printf("----- Fin de carga -----\n");
    }
    return arre;
}

Socio *cargaSubArre(Socio *socios, int N, int &O)
{
    int cont = 0, i;
    O = 0;
    char tipo;
    Socio *subArre;
    printf("Ingrese tipo de socio para seleccionar ('A': Socio deportivo, 'J': Socio Jubilado): ");
    scanf("%c", &tipo);
    while (getchar() != '\n')
        ;
    for (i = 0; i < N; i++)
    {
        if (socios[i].tipos == tipo && socios[i].edad > 40)
        {
            cont++;
        }
    }

    subArre = (Socio *)malloc(cont * sizeof(Socio));

    if (subArre == NULL)
    {
        printf("No se pudo crear el arreglo\n");
    }
    else
    {
        for (i = 0; i < N; i++)
        {
            if (socios[i].tipos == tipo && socios[i].edad > 40)
            {
                subArre[O] = socios[i];
                O++;
            }
        }
    }
    return subArre;
}

Socio *activos(Socio *socios, int N, int &P, char tipo)
{
    Socio *arreglo;
    P = 0;
    int i, cont = 0;

    for (i = 0; i < N; i++)
    {
        if (socios[i].tipos == tipo && strcmp(socios[i].estado, "Activo") == 0)
        {
            cont++;
        }
    }

    arreglo = (Socio *)malloc(cont * sizeof(Socio));

    if (arreglo == NULL)
    {
        printf("No se pudo crear el arreglo\n");
    }
    else
    {
        for (i = 0; i < N; i++)
        {
            if (socios[i].tipos == tipo && strcmp(socios[i].estado, "Activo") == 0)
            {
                arreglo[P] = socios[i];
                P++;
            }
        }
    }
    return arreglo;
}

void mostrarSocios(Socio *socios, int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("- DNI: %d\n", socios[i].DNI);
    }
}

// Se cuenta con información de los socios de un club provincial: DNI, edad, tipo y estado: “Activo “o “Inactivo”. Los
// tipos de socios están determinados por letras: ‘A’: Socio deportivo, …, ‘J’: Socio Jubilado. La cantidad de socios se
// ingresa por teclado.
// Escribir un programa en C que permita:
// a) Cargar los datos en una estructura adecuada. (Validar el ingreso, suponiendo que el tipo de socio varía entre ‘A’
// y ‘J ‘)
// b) Para un tipo de socio determinado, mostrar los DNI de los socios que tienen edad mayor a 40. Generar una
// estructura auxiliar.
// c) Realizar un listado que muestre, cuantas personas se encuentran activas, para cada tipo de socio. Generar una
// estructura auxiliar.

int main()
{
    int N, O, J, D;
    Socio *socios, *subSocios, *aJubilados, *aDeportivo;

    printf("Ingrese la cantidad de socios: ");
    scanf("%d", &N);
    socios = cargaSocios(N);
    subSocios = cargaSubArre(socios, N, O);
    printf("------ DNIs de socios de tipo seleccionado ------\n");
    mostrarSocios(subSocios, O);

    aJubilados = activos(socios, N, J, 'J');
    printf("------ DNIs de socios de jubilados activos ------\n");
    mostrarSocios(aJubilados, J);

    aDeportivo = activos(socios, N, D, 'A');
    printf("------ DNIs de socios de deportivos activos ------\n");
    mostrarSocios(aJubilados, D);
}