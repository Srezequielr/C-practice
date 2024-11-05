#include <stdio.h>
#include <string.h>
#define F 30
#define M 80

typedef struct
{
    int codMed;
    char nombre[20];
    float precio;
} Medicamento;

void cargaMedicamentos(Medicamento medicamentos[M])
{
    int i;

    for (i = 0; i < M; i++)
    {
        printf("Ingresar nombre del medicamento: ");
        scanf("%s", &medicamentos[i].nombre);
        printf("Ingrese precio unitario del medicamento: ");
        scanf("%f", medicamentos[i].precio);
        printf("El codigo del medicamento es: %d", i + 1);
    }
}

void carga(int tabla[F][M])
{
    int i, cod;
    for (i = 0; i < F; i++)
    {
        printf("------ Farmacia %d ------\n", i + 1);
        printf("Ingresar codigo de medicamento <Pasar siguiente farmacia con 0>: ");
        scanf("%d", &cod);

        while (cod != 0)
        {
            printf("Ingrese la cantidad de medicamentos vendidos: ");
            scanf("%d", &tabla[i][cod - 1]);
            printf("Ingresar codigo de medicamento <Pasar siguiente farmacia con 0>: ");
            scanf("%d", &cod);
        }
        printf("----------------\n");
    }
}

void calcUnidadesXMed(int tabla[F][M])
{
    int i, j, vendidas;

    for (i = 0; i < F; i++)
    {
        vendidas = 0;
        for (i = 0; i < M; i++)
        {
            vendidas += tabla[i][j];
        }

        printf("La cantidad vendida de este medicamento es de %d unidades\n", vendidas);
    }
}

void codMayorRec(int tabla[F][M], Medicamento medicamentos[M])
{
    int i, j, vendidas, cod;
    float mayor, recaudado;
    for (i = 0; i < F; i++)
    {
        recaudado = 0;
        for (j = 0; j < M; j++)
        {
            recaudado += tabla[i][j] * medicamentos[j].precio;
        }
        if (recaudado > mayor)
        {
            mayor = recaudado;
            cod = j;
        }
    }
    printf("El codigo de medicamento con mayor recaudacion es: %d\n", cod);
}

void cantVendida(int tabla[F][M])
{
    int i, j, totalVend = 0;

    printf("Ingresar codigo de medicamento: ");
    scanf("%d", &j);

    for (i = 0; i < F; i++)
    {
        totalVend += tabla[i][j];
    }
    printf("El medicamento seleccionado tiene %d unidades vendidas\n", totalVend);
}

void calcImpUni(int tabla[F][M], Medicamento medicamentos[M])
{
    char nombre[20];
    int i, j, totalVend, impTotal;

    printf("Ingresar nombre del medicamento a buscar: ");
    scanf("%d", &nombre);

    while ((j < M) && (strcmp(nombre, medicamentos[j - 1].nombre)))
    {
        j++;
    }
    if (j == M)
    {
        printf("No se encontro el medicamento\n");
    }
    else
    {
        for (i = 0; i < F; i++)
        {
            totalVend += tabla[i][j];
        }
        printf("El total vendido del medicamento buscado es de %d y el importe total de %d", totalVend, totalVend * medicamentos[j - 1].precio);
    }
}

// Un laboratorio abastece a 30 farmacias de la provincia. Dicho laboratorio comercializa 80 medicamentos (1..80) de los que se debe registrar: Código de medicamento, nombre y precio unitario.
// Se ingresan las ventas realizadas ordenada por farmacia. Por cada venta a una farmacia se ingresa: código de medicamento y cantidad de unidades, finalizando con código de medicamento igual a 0 (cero), como lo muestra el siguiente ejemplo:
// Codificar un programa en C, que utilizando funciones permita:
// 1. Calcular y mostrar total de unidades vendidas de cada uno de los medicamentos.
// 2. Escribir el/los códigos/s del/los medicamento/s por el que se recaudó mayor importe.
// 3. Indicar la cantidad de unidades vendidas para un código de medicamento ingresado por teclado.
// 4. Dado el nombre de un medicamento indicar el importe total recaudado y la cantidad de unidades vendidas.
// 5. Indicar la cantidad de unidades vendida a cada farmacia y el importe total que pagó cada una.

int main()
{
    int tabla[F][M];
    Medicamento medicamentos[M];

    cargaMedicamentos(medicamentos);
    carga(tabla);
    calcUnidadesXMed(tabla);
    codMayorRec(tabla, medicamentos);
    cantVendida(tabla);
    calcImpUni(tabla, medicamentos);
    return 0;
}
