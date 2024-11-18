#include <stdio.h>
#define M 3
#define D 4

void cereo(int tabla[M][D])
{
    int i, j;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < D; j++)
        {
            tabla[i][j] = 0;
        }
    }
}

void carga(int tabla[M][D])
{
    int mes, depto;

    printf("Ingrese mes (1-6) para cargar <Cancelar con 0>: ");
    scanf("%d", &mes);

    while (mes != 0)
    {
        printf("Ingresar numero de departamento (1-8): ");
        scanf("%d", &depto);
        printf("Ingrese importe recaudado: ");
        scanf("%d", &tabla[mes][depto]);
        printf("Ingrese mes para cargar <Cancelar con 0>: ");
        scanf("%d", &mes);
    }
}

int menorImporte(int tabla[M][D])
{
    int i, j, total, menor = 9999999, numMen;
    for (j = 0; j < D; j++)
    {
        total = 0;
        for (i = 0; i < M; i++)
        {
            total += tabla[i][j];
        }
        if (total < menor)
        {
            menor = total;
            numMen = j;
        }
    }
    return j;
}

int calcProm(int tabla[M][D])
{
    int i, j, prom = 0;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < D; j++)
        {
            prom += tabla[i][j];
        }
    }
    prom = prom / (M * D);
    return prom;
}

void supProm(int tabla[M][D], int prom)
{
    int i, j;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < D; j++)
        {
            if (tabla[i][j] > prom)
            {
                printf("El departamento %d supera el promedio\n", j + 1);
            }
        }
    }
}

// Un supermercado ingresa las ventas de los últimos 6 meses, realizadas en los 8 departamentos de venta que posee.
// Por cada venta se ingresa mes, departamento e importe. Las ventas no traen ningún orden particular. Realizar un
// programa en C, que a través de funciones permita:
// 1. Almacenar la información en una tabla que posea por cada mes, el importe total de ventas de cada
// departamento.
// 2. Mostrar en el programa principal el departamento que tuvo menor importe de venta (suponer único).
// 3. Mostrar importe promedio de venta del supermercado.
// 4. Mostrar el/los departamento/s que supera/n la venta promedio, indicando el importe total vendido a lo largo
// del semestre.

int main()
{
    int tabla[M][D], menorVenta, prom;

    cereo(tabla);
    carga(tabla);
    menorVenta = menorImporte(tabla);
    printf("El departamento que registro menos importe es el numero %d\n", menorVenta + 1);
    prom = calcProm(tabla);
    printf("El promedio de ventas es de %d\n", prom);
    supProm(tabla, prom);
}