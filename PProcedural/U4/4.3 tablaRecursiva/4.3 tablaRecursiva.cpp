#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2
#define M 3

void cargaRecursiva(float tabla[N][M], int i, int j)
{
    if (i == N)
    {
        return;
    }
    tabla[i][j] = (float)rand() / RAND_MAX * 100;

    if (j < M - 1)
    { // Avanza en la misma fila
        cargaRecursiva(tabla, i, j + 1);
    }
    else
    { // Cambia a la siguiente fila y vuelve a la primera columna
        cargaRecursiva(tabla, i + 1, 0);
    }
}

void mostrarRecursivo(float tabla[N][M], int i, int j)
{

    if (i == N)
    {
        return;
    }

    printf("Elemento en [%d][%d]: %f\n", i, j, tabla[i][j]);

    if (j < M - 1)
    { // Avanza en la misma fila
        mostrarRecursivo(tabla, i, j + 1);
    }
    else
    { // Cambia a la siguiente fila y vuelve a la primera columna
        mostrarRecursivo(tabla, i + 1, 0);
    }
}

// Dada una tabla de N x M números enteros hacer en forma recursiva:
// a) Cargar la información ordenada por columnas.
// b) Mostrar el contenido de la tabla con formato de reales.

int main()
{
    float tabla[N][M], i = 0, j = 0;
    cargaRecursiva(tabla, i, j);
    mostrarRecursivo(tabla, i, j);
}