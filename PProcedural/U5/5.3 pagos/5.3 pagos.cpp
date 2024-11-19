#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    int codPlan;
    float deuda;
} Adj;

Adj *cargaAdjud(int N)
{
    int i;
    Adj *arreglo;

    arreglo = (Adj *)malloc(N * sizeof(Adj));

    if (arreglo == NULL)
    {
        printf("El arreglo no se ha creado");
    }
    else
    {
        printf("------ Carga de adjudicatarios ------\n");
        for (i = 0; i < N; i++)
        {
            printf("Ingresar DNI del adjudicatario: ");
            scanf("%d", &arreglo[i].dni);
            while (getchar() != '\n')
                ;
            printf("Ingresar codigo de plan del adjudicartario (1-5): ");
            scanf("%d", &arreglo[i].codPlan);
            while (getchar() != '\n')
                ;
            printf("Ingese deuda del adjudicatario: ");
            scanf("%f", &arreglo[i].deuda);
        }
        printf("----- Fin de carga -----\n");
    }
    return arreglo;
}

void buscarDni(Adj *arreglo, int N)
{
    int dni, i = 0;

    printf("Ingresar DNI para buscar: ");
    scanf("%d", &dni);

    while (arreglo[i].dni != dni && i < N)
    {
        i++;
    }
    if (i == N)
    {
        printf("DNI no encontrado\n");
    }
    else
    {
        printf("El adjudicatario esta adherido al plan %d y adeuda %.2f$\n", arreglo[i].codPlan, arreglo[i].deuda);
    }
}

void cerear(int planes[5])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        planes[i] = 0;
    }
}

void contPlanes(Adj *arreglo, int planes[5], int N)
{

    int i, j;

    for (i = 0; i < N; i++)
    {
        planes[arreglo[i].codPlan - 1]++;
    }

    printf("La cantidad de adjudicatarios por plan son: \n");
    for (i = 0; i < 5; i++)
    {
        printf("- Plan %d: %d adjuducatarios\n", i + 1, planes[i]);
    }
}

// El Instituto Provincial de la Vivienda ha implementado un sistema que consta de 5 planes de pago distintos, con el fin
// de que los adjudicatarios de sus viviendas puedan cancelar sus deudas. Se ingresa la cantidad de adjudicatarios y por
// cada uno de ellos el DNI, código de plan al que adhiere (1..5) y monto adeudado.
// Se pide:
// a) Cargar en una estructura de datos adecuada la información que se posee.
// b) Para un adjudicatario cuyo DNI se ingresa por teclado, indicar el número de plan al cual se adhirió y el monto
// adeudado.
// c) Indicar para cada plan cuantos adjudicatarios adhirieron.

int main()
{
    int N, planes[5];
    Adj *adjudicatarios;

    printf("Ingrese cantidad de adjudicatarios: ");
    scanf("%d", &N);
    adjudicatarios = cargaAdjud(N);
    buscarDni(adjudicatarios, N);
    cerear(planes);
    contPlanes(adjudicatarios, planes, N);
}