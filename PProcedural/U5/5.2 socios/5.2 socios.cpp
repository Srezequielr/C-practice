#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int DNI;
    int edad;
    char estado[10];
    char tipos;
} Socio;

int *cargaSocios(int N)
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
            printf("Ingrese edad del socio: ");
            scanf("%d", &arre[i].edad);
            printf("Ingese tipo de socio ('A': Socio deportivo, 'J': Socio Jubilado): ");
            scanf("%c", &arre[i].estado);
            printf("Ingrese estado del socio (Activo o Inactivo): ");
            scanf("%s", &arre[i].estado);
        }
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
    int N;
    Socio *socios;

    printf("Ingrese la cantidad de socios: ");
    scanf("%d", &N);
    
}