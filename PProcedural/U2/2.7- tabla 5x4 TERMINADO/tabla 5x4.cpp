#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define F 5
#define C 4

void carga(int tabla[F][C])
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {
            tabla[i][j] = rand() % 200;
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

void promColum(int tabla[F][C])
{
    int i, j, acum = 0;
    float prom;
    for (i = 0; i < F; i++)
    {
        acum = acum + tabla[i][2];
    }
    prom = acum / F;
    printf("Total de la tercer fila: %d\n", acum);
    printf("El promedio de la tercer fila es de %.2f \n", prom);
}

void mayorCien(int tabla[F][C])
{
    int i, j, cont = 0;
    for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (tabla[i][j] > 100)
            {
                cont++;
            }
        }
    }
    printf("Los numeros registrados mayores a 100 son: %d\n", cont);
}

int main()
{
    int tabla[F][C];
    carga(tabla);
    promColum(tabla);
    mayorCien(tabla);
    mostrar(tabla);
    return 0;
}