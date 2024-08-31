#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define F 3
#define C 4

void carga(int tabla[F][C])
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {
            tabla[i][j] = rand() % 20;
        }
    }
}

void mostrar(int tabla[F][C])
{
    int i, j;

    for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("%d | ", tabla[i][j]);
        }
        printf("\n");
    }
}

int sumaImpar(int tabla[F][C])
{
    int i, j, acum = 0;
    for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (tabla[i][j] % 2 != 0)
                acum += tabla[i][j];
        }
    }
    return acum;
}

int mayorDiez(int tabla[F][C])
{
    int fila, i, cont = 0;
    printf("Ingrese numero de Fila: ");
    scanf("%d", &fila);
    for (i = 0; i < C; i++)
    {
        if (tabla[fila - 1][i] > 10)
        {
            cont++;
        }
    }
    return cont;
}

int main()
{
    int tabla[F][C], mayorADiez;
    carga(tabla);
    mostrar(tabla);
    printf("La suma de los numeros impares es de %d \n", sumaImpar(tabla));
    mayorADiez = mayorDiez(tabla);
    printf("Los numeros mayores a 10 son: %d", mayorADiez);
}

// pertile agustin
