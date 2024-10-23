#include <stdio.h>
#define N 6

void cerear(int xEncuesta[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        xEncuesta[i] = 0;
    }
}

void cargaEncuesta(int xEncuesta[N])
{
    int bandera;
    printf("Ingrese codigo de lenguaje votado (0 para cancelar) \n");
    printf("1: JavaScript \n2: HTML \n3: CSS \n4: Java \n5: Python \n6: C \n");
    scanf("%d", &bandera);
    while (bandera != 0)
    {
        xEncuesta[bandera - 1]++;
        printf("Ingrese codigo de lenguaje votado (0 para cancelar): ");
        scanf("%d", &bandera);
    }
}

void menosElegidos(int xEncuesta[N], char *xNombres[])
{
    int i;
    printf("Los lenguajes menos elegidos son:");
    for (i = 0; i < N; i++)
    {
        if (xEncuesta[i] < 5)
        {
            printf("- %s\n", xNombres[i]);
        }
    }
}

void masElegido(int xEncuesta[N], char *xNombres[])
{
    int i, max = 0;
    for (i = 0; i < N; i++)
    {
        if (xEncuesta[i] > max)
        {
            max = i;
        }
    }
    printf("El lenguaje mas elegido fue: %s", xNombres[max]);
}

void totalEncuestas(int xEncuestas[N])
{
    int i, cont = 0;
    for (i = 0; i < N; i++)
    {
        cont += xEncuestas[i];
    }
    printf("La cantidad total de encuestados fue de: %d", cont);
}

int contRecursivo(int xEncuesta[N], int &xMenosCincoMil, int xMasNueveMil, int i)
{

    if (i < N)
    {
        if (xEncuesta[i] < 5000)
        {
            xMenosCincoMil++;
        }
        if (xEncuesta[i] > 9000)
        {
            xMasNueveMil++;
        }
        return contRecursivo(xEncuesta, xMenosCincoMil, xMasNueveMil, i + 1);
    }
    return xMasNueveMil;
}

int main()
{
    int encuesta[N], menosCincoMil = 0, masNueveMil = 0, i = 0;
    char *nombres[] = {"JavaScript", "HTML", "CSS", "Java", "Python", "C"};
    cerear(encuesta);
    cargaEncuesta(encuesta);
    menosElegidos(encuesta, nombres);
    masElegido(encuesta, nombres);
    masNueveMil = contRecursivo(encuesta, menosCincoMil, masNueveMil, i);
    printf("%d fueron elegidos por mas de 9000 y %d fueron elegidos por menos de 5000", masNueveMil, menosCincoMil);
}