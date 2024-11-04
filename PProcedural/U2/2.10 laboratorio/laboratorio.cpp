#include <stdio.h>
#define F 5
#define M 80

void cerear(int tabla[F][M])
{
    int i, j;

    for (i = 0; i < F; i++)
    {
        for (j = 0; j < M; j++)
        {
            tabla[i][j] = 0;
        }
    }
}

void carga(int tabla[F][M])
{
    int i, codigo, cantVentas;
    for (i = 0; i < F; i++)
    {
        printf("-------- Farmacia %d --------\n", i + 1);
        printf("Ingresar codigo de medicamento (100-179) <0 para pasar sig farmacia>: ");
        scanf("%d", &codigo);
        while (codigo != 0)
        {
            printf("Ingresar cantidad de medicamentos: ");
            scanf("%d", &cantVentas);

            tabla[i][codigo - 100] += cantVentas;
            printf("Ingresar codigo de medicamento (100-179) <0 para pasar sig farmacia>: ");
            scanf("%d", &codigo);
        }
    }
}

void buscarMasVendido(int tabla[])
{
    int i, max = 0, cod;
    for (i = 0; i < M; i++)
    {
        if (max < tabla[i])
        {
            max = tabla[i];
            cod = i;
        }
    }
    printf("El codigo del medicamento mas vendido es: %d", cod + 100);
}

// Un laboratorio abastece a 30 farmacias de la provincia (las farmacias están codificadas con números entre 1 y 30).
// Dicho laboratorio comercializa 80 medicamentos (con código desde 100 hasta 179).
// En forma ordenada por las farmacias se ingresan las ventas realizadas. Por cada venta se ingresa: código de
// medicamento y cantidad de unidades, finalizando con código de medicamento igual a 0 (cero)
// Codificar un programa en C, que utilizando funciones permita:
// a) Realizar la carga de la tabla.
// b) Calcular y mostrar el total de unidades vendidas de cada uno de los medicamentos.
// c) Dado el código de una farmacia, indicar el código del medicamento más vendido.

int main()
{
    int tabla[F][M], codFarmacia;
    cerear(tabla);
    carga(tabla);

    // mostrar(tabla);
    printf("Ingrese codigo de farmacia para buscar: ");
    scanf("%d", &codFarmacia);
    buscarMasVendido(tabla[codFarmacia - 1]);
}