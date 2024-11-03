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

// Realizar un programa en lenguaje C, que usando funciones óptimas realice lo siguiente:
// a) Generar y cargar un arreglo bidimensional de enteros de 3x4.
// b) Mostrar en el main la suma de los elementos con valor impar.
// c). Ingresar un número de fila y mostrar en el main la cantidad de elementos mayores a 10 (realice una función que
// devuelva la cantidad al main). 

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
