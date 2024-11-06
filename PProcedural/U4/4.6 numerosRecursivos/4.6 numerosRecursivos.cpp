#include <stdio.h>
#define N 7

void carga(int arre[N], int i)
{
    if (i < N)
    {
        printf("Escriba un numero: ");
        scanf("%d", &arre[i]);
        carga(arre, i + 1);
    }
}

int calcProm(int arre[N], int i, int prom)
{
    if (i < N)
    {
        prom = prom + arre[i];
        return calcProm(arre, i + 1, prom);
    }
    else
    {
        return (prom / N);
    }
}

int cargaSubArre(int arre[N], int subArre[N], int i, int prom, int &j)
{
    if (i < N)
    {
        if (arre[i] >= prom)
        {
            subArre[j] = arre[i];
            j++;
            return cargaSubArre(arre, subArre, i + 1, prom, j);
        }
        else
        {
            return cargaSubArre(arre, subArre, i + 1, prom, j);
        }
    }
    else
    {
        return j;
    }
}

void masIgualProm(int subArre[N], int mayorProm, int igualProm, int prom, int i, int j)
{
    if (i < j)
    {
        if (subArre[i] > prom)
        {
            mayorProm++;
        }
        else
        {
            igualProm++;
        }
        masIgualProm(subArre, mayorProm, igualProm, prom, i + 1, j);
    }
    else
    {
        printf("Las componentes que son iguales al promedio son %d y las mayores al mismo son %d \n", igualProm, mayorProm);
    }
}

int busquedaSubArre(int subArre[N], int busqueda, int i, int j)
{
    if ((i < j) && (subArre[i] != busqueda))
    {
        i++;
        return busquedaSubArre(subArre, busqueda, i, j);
    }
    else
    {
        return i;
    }
}

// Construir un programa en lenguaje C que a través de funciones recursivas resuelva los siguientes ítems: 
// a) Cargar un arreglo de enteros, de N componentes. 
// b) Generar un subarreglo con las componentes del arreglo cargado, cuyo valor es mayor o igual al Promedio. 
// c) Indicar cuantas componentes del subarreglo son mayores al promedio y cuantas iguales a éste.  
// d) Ingresar un número y decir si se encuentra en el subarreglo. 
// e) Realice el ítem anterior si el arreglo original estuviera ordenado ascendentemente. 

int main()
{
    int arre[N], subArre[N], i = 0, prom = 0, j = 0, mayorProm = 0, igualProm = 0, busqueda, bandera;
    carga(arre, i);
    prom = calcProm(arre, i, prom);
    printf("El promedio es: %d\n", prom);
    j = cargaSubArre(arre, subArre, i, prom, j);
    masIgualProm(subArre, mayorProm, igualProm, prom, i, j);
    printf("Ingrese un numero para buscar en el sub arreglo: ");
    scanf("%d", &busqueda);
    bandera = busquedaSubArre(subArre, busqueda, i, j);
    if (bandera == j)
    {
        printf("El numero no se encontro");
    }
    else
    {
        printf("El numero si se encontro");
    }
}