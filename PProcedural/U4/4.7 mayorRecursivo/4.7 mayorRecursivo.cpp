#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void carga(int arreglo[N])
{
    int i;
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        arreglo[i] = rand() % 10;
    }
}

void mostrar(int arreglo[N])
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf(". %d\n", arreglo[i]);
    }
}

void buscarMayor(int arreglo[N], int i, int &mayor)
{
    if (i < N)
    {
        if (arreglo[i] > mayor)
        {
            mayor = arreglo[i];
        }
        buscarMayor(arreglo, i + 1, mayor);
    }
    if (arreglo[i] == mayor)
    {
        printf(". %d es igual al mayor\n", arreglo[i]);
    }
}

// Ejercicio 7
// Realice una función que busque el mayor valor de un arreglo, de modo tal que al llegar al caso base ya haya
// encontrado este valor; y en la etapa de volver al punto de invocación vaya mostrando los valores iguales al mayor.

int main()
{
    int arreglo[N], mayor = 0, i = 0;
    carga(arreglo);

    mostrar(arreglo);
    buscarMayor(arreglo, i, mayor);
}