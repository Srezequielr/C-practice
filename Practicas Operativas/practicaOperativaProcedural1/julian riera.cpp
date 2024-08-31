// Practica Operativa: Riera Julian Ezequiel -- Silvina Balmaceda

#include <stdio.h>
#define N 3
#define C 4

void cerear(int tabla[N][C])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < C; j++)
        {
            tabla[i][j] = 0;
        }
    }
    return;
}

void mostrar(int tabla[N][C])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("%d | ", tabla[i][j]);
        }
        printf("\n");
    }
    return;
}

// void cargaVenta(int tabla[N][C])
// {
//     int tCerveza, nNegocio, uVendidas;
//     printf("Ingresar el tipo de cerveza vendida (Finalizar con 0): ");
//     scanf("%d", &tCerveza);
//     while (tCerveza != 0)
//     {
//         printf("Ingrese numero de negocio: ");
//         scanf("%d", &nNegocio);
//         printf("Ingrese cantidades de unidades vendidas: ");
//         scanf("%d", &uVendidas);
//         tabla[nNegocio - 1][tCerveza - 1] = tabla[nNegocio - 1][tCerveza - 1] + uVendidas;
//         printf("Ingresar el tipo de cerveza vendida (Finalizar con 0): ");
//         scanf("%d", &tCerveza);
//     }
//     return;
// }

void cargaVenta(int tabla[N][C])
{
    int tCerveza, nNegocio, uVendidas, i;

    for (i = 0; i < N; i++)
    {
        printf("-------Negocio %d-------\n", i +1);
        printf("Ingresar el tipo de cerveza vendida (Finalizar con 0): ");
        scanf("%d", &tCerveza);
        while (tCerveza != 0)
        {
            printf("Ingrese cantidades de unidades vendidas: ");
            scanf("%d", &uVendidas);
            tabla[i][tCerveza - 1] = tabla[i][tCerveza - 1] + uVendidas;
            printf("Ingresar el tipo de cerveza vendida (Finalizar con 0): ");
            scanf("%d", &tCerveza);
        }
    }

    while (tCerveza != 0)
    {
        printf("Ingrese numero de negocio: ");
        scanf("%d", &nNegocio);
        printf("Ingrese cantidades de unidades vendidas: ");
        scanf("%d", &uVendidas);
        tabla[nNegocio - 1][tCerveza - 1] = tabla[nNegocio - 1][tCerveza - 1] + uVendidas;
        printf("Ingresar el tipo de cerveza vendida (Finalizar con 0): ");
        scanf("%d", &tCerveza);
    }
    return;
}

void calcVentXCerv(int tabla[N][C])
{
    int i, j, totalXTipo = 0;
    for (j = 0; j < C; j++)
    {
        for (i = 0; i < N; i++)
        {
            totalXTipo = totalXTipo + tabla[i][j];
        }
        printf("El total vendido de la cerveza %d es de %d\n", j + 1, totalXTipo);
        totalXTipo = 0;
    }
}

int ventaXTipo(int tabla[N][C])
{
    int input, i, acum = 0;
    printf("Ingrese codigo de cerveza: ");
    scanf("%d", &input);
    for (i = 0; i < N; i++)
    {
        acum = acum + tabla[i][input - 1];
    }
    return acum;
}

int main()
{
    int tabla[N][C], venta;
    cerear(tabla);
    cargaVenta(tabla);
    calcVentXCerv(tabla);
    venta = ventaXTipo(tabla);
    printf("El total de ventas del tipo de cerveza seleccionado es de: %d\n", venta);
    // mostrar(tabla);
    // Descomentar linea para testear la tabla
}
