#include <stdio.h>
#include <string.h>

void calc(int mes, char *semilla)
{
    switch (mes)
    {
    case 1 ... 3:
        if (strcmp(semilla, "rosa") == 0)
        {
            printf("Es posible plantar %ss en el mes seleccionado", semilla);
        }
        else
        {
            printf("No es posible cultivar %s pero puede cultivar rosas", semilla);
        }
        break;
    case 4:
        if (strcmp(semilla, "camelia") == 0)
        {
            printf("Es posible plantar %ss en el mes seleccionado", semilla);
        }
        else
        {
            printf("No es posible cultivar %s pero puede cultivar camelias", semilla);
        }
        break;
    case 5:
        if (strcmp(semilla, "clavel") == 0)
        {
            printf("Es posible plantar %ses en el mes seleccionado", semilla);
        }
        else
        {
            printf("No es posible cultivar %s pero puede cultivar claveles", semilla);
        }
        break;
    case 6 ... 7:
        if (strcmp(semilla, "lirio") == 0)
        {
            printf("Es posible plantar %sos en el mes seleccionado", semilla);
        }
        else
        {
            printf("No es posible cultivar %s pero puede cultivar lirios", semilla);
        }
        break;
    case 8:
        if (strcmp(semilla, "azucena") == 0)
        {
            printf("Es posible plantar %ss en el mes seleccionado", semilla);
        }
        else
        {
            printf("No es posible cultivar %s pero puede cultivar azucenas", semilla);
        }
        break;
    case 9 ... 12:
        if (strcmp(semilla, "dalia") == 0)
        {
            printf("Es posible plantar %ss en el mes seleccionado", semilla);
        }
        else
        {
            printf("No es posible cultivar %s pero puede cultivar dalias", semilla);
        }
        break;
    default:
        printf("Mes invalido");
    }
}

int main()
{
    int mes;
    char semilla[20];
    printf("Ingrese el mes en que quiere plantar la semilla \n");
    scanf("%d", &mes);
    printf("Ingrese nombre de la semilla que quiere plantar \n");
    scanf("%s", &semilla);
    calc(mes, semilla);
    return 0;
}
