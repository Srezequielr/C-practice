#include <stdio.h>
#define N 30

void cerear(float temperaturas[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        temperaturas[i] = -999;
    }

    return;
}

void carga(float temperaturas[N])
{
    int marca;
    do
    {
        printf("Ingrese el numero de dia, cancelar con -1 \n");
        scanf("%d", &marca);
        if (marca != -1)
        {
            printf("Ingrese temperatura registrada \n");
            scanf("%f", &temperaturas[marca - 1]);
        }

    } while (marca != -1);
    return;
}

void muestra(float temperaturas[N])
{
    int i;
    printf("Las temperaturas registrada en dias impares son: \n");
    for (i = 0; i < N; i++)
    {
        if ((i + 1) % 2 != 0)
        {
            printf("La temperatura registrada el dia %d es: ", i + 1);
            if (temperaturas[i] != -999)
            {
                printf("%f \n", temperaturas[i]);
            }
            else
            {
                printf("Este dia no tiene temperatura cargada \n");
            }
        }
    }
    return;
}

void menorTemp(float temperaturas[N])
{
    int min, i;
    min = 999999;
    for (i = 0; i < N; i++)
    {
        if (temperaturas[i] != -999)
        {
            if (temperaturas[i] < min)
            {
                min = temperaturas[i];
            }
        }
    }
    printf("Los dias que registraron la temperatura minima son: \n");
    for (i = 0; i < N; i++)
    {
        if (min == temperaturas[i])
        {
            printf("%d \n", i + 1);
        }
    }
}

void mayorTemp(float temperaturas[N])
{
    int max, i;
    max = -99999;
    for (i = 0; i < N; i++)
    {
        if (temperaturas[i] != -999)
        {
            if (temperaturas[i] > max)
            {
                max = temperaturas[i];
            }
        }
    }
    printf("Los dias que registraron la temperatura maxima son: \n");
    for (i = 0; i < N; i++)
    {
        if (max == temperaturas[i])
        {
            printf("%d \n", i + 1);
        }
    }
}

void cambiarVal(float temperaturas[N])
{
    int dia1, dia2;
    float aux;
    printf("Ingrese el dia que quiera reemplazar");
    scanf("%d", &dia1);
    printf("Escriba el dia con el que va a intercambiar");
    scanf("%d", &dia2);
    aux = temperaturas[dia1 - 1];
    temperaturas[dia1 - 1] = temperaturas[dia2 - 1];
    temperaturas[dia2 - 1] = aux;
    printf("Intercambio correcto");
    return;
}

int main()
{
    int i;
    float temperaturas[N];
    cerear(temperaturas);
    carga(temperaturas);
    muestra(temperaturas);
    menorTemp(temperaturas);
    mayorTemp(temperaturas);
}