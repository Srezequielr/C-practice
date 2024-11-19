#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 12
#define C 20

void carga(int tabla[M][C])
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < C; j++)
        {
            tabla[i][j] = rand() % 20;
        }
    }
}

int calcMesCinco(int tabla[], int cont, int i)
{

    if (i < C)
    {
        cont += tabla[i];
        return calcMesCinco(tabla, cont, i + 1);
    }
    else
    {
        return cont;
    }
}

void calcPromMaq(int tabla[M][C], int i, int j, int prom)
{
    if (j == C) // Si procesamos todas las máquinas (columnas)
    {
        return;
    }

    if (i < M) // Avanzamos por las filas para sumar
    {
        prom += tabla[i][j];
        calcPromMaq(tabla, i + 1, j, prom);
    }
    else // Cambiamos a la siguiente máquina (columna)
    {
        printf("El promedio de la máquina %d es de %d\n", j + 1, prom / M);
        calcPromMaq(tabla, 0, j + 1, 0); // Reiniciamos para la siguiente columna
    }
}

void mostrarMasGasto(int tabla[M][C], int i, int j, int mayor, int mesMayor)
{
    if (j == C) // Si procesamos todas las máquinas (columnas)
    {
        return;
    }

    if (i < M) // Recorremos las filas (meses) para una máquina específica
    {
        if (tabla[i][j] > mayor) // Actualizamos el mayor gasto y su mes
        {
            mayor = tabla[i][j];
            mesMayor = i;
        }
        mostrarMasGasto(tabla, i + 1, j, mayor, mesMayor);
    }
    else // Terminamos de procesar los meses de una máquina (columna)
    {
        printf("La máquina %d gastó más en el mes %d con un gasto de %d\n", j + 1, mesMayor + 1, mayor);
        mostrarMasGasto(tabla, 0, j + 1, 0, 0); // Reiniciamos para la siguiente máquina
    }
}

// Una empresa constructora posee la cantidad de litros de combustible que utilizó cada una de las 20 máquinas
// motoniveladoras en los últimos 12 meses.
// Generar una tabla y guardar dicha información, donde las filas representen los meses.
// Realizar un programa en C, que usando funciones recursivas muestre:
// a) La cantidad total de combustible que la empresa utilizó en el mes 5. (La función recursiva solo debe recibir como
// parámetro la fila del mes indicado).
// b) El gasto promedio de combustible de cada una de las máquinas.
// c) El mes con mayor gasto de combustible de cada una de las máquinas.

int main()
{
    int tabla[M][C], cont = 0, i = 0;
    carga(tabla);
    cont = calcMesCinco(tabla[4], cont, i);
    printf("La cantidad de combustible que se utilizo en el mes 5 fueron %d litros\n", cont);
    calcPromMaq(tabla, i, i, i);
    mostrarMasGasto(tabla, i, i, i, i);
}