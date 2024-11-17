#include <stdio.h>
#define M 6
#define D 8

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
    int tabla[M][D];

    cereo(tabla);
}