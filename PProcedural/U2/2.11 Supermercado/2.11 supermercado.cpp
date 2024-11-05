#include <stdio.h>
#define M 12
#define D 8

void cerear(int tabla[M][D])
{
    int i, j;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < D; j++)
        {
            tabla[i][j];
        }
    }
}

void carga(int tabla[M][D])
{
    int mes, depto;

    printf("Ingrese numero de mes <Cancelar con 0>: ");
    scanf("%d", &mes);
    while (mes != 0)
    {
        printf("Ingresar numero de departamento (1-8)");
        scanf("%d", &depto);
        printf("Ingresar la cantidad de ventas del departamento: ");
        scanf("%d", tabla[mes - 1][depto - 1]);
        printf("Ingrese numero de mes <Cancelar con 0>: ");
        scanf("%d", &mes);
    }
}

int menosVendio(int tabla[])
{
    int min = 9999999, i, cod;
    for (i = 0; i < D; i++)
    {
        if (min > tabla[i])
            ;
        {
            min = tabla[i];
            cod = i;
        }
    }
    return cod;
}

int calcProm(int tabla[M][D])
{
    float prom = 0;
    int i, j;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < D; j++)
        {
            prom += tabla[i][j];
        }
    }
    prom = prom / D;
    return prom;
}

void supProm(int tabla[M][D], int prom)
{
    int mes, super;
    printf("Ingrese numero de mes: ");
    scanf("%d", &mes);
    printf("Ingrese numero de departemento : ");
    scanf("%d", &super);

    if (tabla[mes - 1][super - 1] > prom)
    {
        printf("El valor supera el promedio");
    }
    else
    {
        printf("El valor no supera el promedio");
    }
}

// Un supermercado ingresa las ventas de los últimos 6 meses, realizadas en los 8 departamentos de venta que posee.
// Por cada venta se ingresa mes (1 ... 12), número de departamento (1 ... 8) e importe. Las ventas no traen ningún orden
// particular. Realizar un programa en C, que a través de funciones permita:
// a) Almacenar la información en una tabla que posea por cada mes, el importe total de ventas de cada departamento.
// La carga finaliza con mes igual a cero.
// b) Dado un mes, mostrar en el programa principal el departamento que menos vendió (suponer único).
// c) Mostrar el importe promedio de venta del supermercado.
// d) Dado un mes y un departamento, indicar si supera el importe promedio del ítem anterior.

int main()
{
    int tabla[M][D], mes, menorVenta, prom;
    cerear(tabla);
    carga(tabla);

    printf("Ingese mes a buscar menos vendido: ");
    scanf("%d", &mes);
    menorVenta = menosVendio(tabla[mes - 1]);
    printf("El departamento que menos vendio es el %d\n", menorVenta + 1);

    prom = calcProm(tabla);
    printf("El promedio de venta es de %d\n", prom);

    supProm(tabla, prom);
}