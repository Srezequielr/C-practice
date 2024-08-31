#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

void carga(int arreglo[N])
{
    int i, max = 20, min = -20;
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {

        arreglo[i] = (rand() % (max - min + 1)) + min;
    }
}

void mostrar(int arreglo[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Numero %d\n", arreglo[i]);
    }
}

void calcularPosNeg(int arreglo[N], int &positivos, int &negativos)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (arreglo[i] < 0)
        {
            negativos++;
        }
        else
        {
            positivos++;
        }
    }
}

int sumaPosParesImpares(int arreglo[N], int posPares, int &posImares)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            posPares = posPares + arreglo[i];
        }
        else
        {
            posImares = posImares + arreglo[i];
        }
    }

    return posPares;
}

void busqueda(int arreglo[N])
{
    int input, i = 0;
    printf("Ingrese el numero que quiere buscar: ");
    scanf("%d", &input);
    while (input != arreglo[i] && i < N)
    {
        i++;
    }
    if (i == N)
    {
        printf("No se encontro el numero solicitado");
    }
    else
    {
        printf("El numero buscado se encuentra en la posicion %d", i);
    }
}

int main()
{
    int arreglo[N], positivos = 0, negativos = 0, posImares = 0, posPares = 0;
    carga(arreglo);
    mostrar(arreglo);
    calcularPosNeg(arreglo, positivos, negativos);
    if (positivos >= negativos)
    {
        printf("La cantidad de numeros mayores a cero es mayor o igual a la cantidad e numeros menores a cero \n");
    }
    posPares = sumaPosParesImpares(arreglo, posPares, posImares);
    printf("La suma de los numeros en posiciones impares es de: %d y la de posiciones pares de: %d \n", posImares, posPares);
    busqueda(arreglo);
}