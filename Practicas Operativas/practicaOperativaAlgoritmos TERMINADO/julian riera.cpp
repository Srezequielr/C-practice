#include <stdio.h>
#define N 7

void carga(float arreglo[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Ingrese el valor numero %d \n", i + 1);
        scanf("%f", &arreglo[i]);
    }
    return;
}

void printPares(float arreglo[N])
{
    int i, cont, parteEntera;
    cont = 0;
    for (i = 0; i < N; i++)
    {
        parteEntera = (int)arreglo[i];
        if (parteEntera % 2 == 0)
        {
            cont++;
        }
    }
    printf("La cantidad de componentes pares es de %d (Solo se toma la parte entera)\n", cont);
    return;
}

void sumaTotal(float arreglo[N]){
    int i;
    float acum;
    for(i = 0; i < N; i++){
        acum = acum + arreglo[i];
    }
    printf("La totalidad de la suma de los componentes es de: %f \n", acum);
}

int main()
{
    printf("Julian Riera \n");
    float arreglo[N];
    carga(arreglo);
    printPares(arreglo);
    sumaTotal(arreglo);
}

// • Generar un arreglo de 7 componentes reales, agregue un mensaje donde figure su nombre y apellido.
// • Decir la cantidad de componentes con valores pares.
// • Mostrar la suma de las componentes.

// 14.03 28.65 59.43 3.09 72.11 43.53 24.08  <--- lote de prueba