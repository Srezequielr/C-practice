#include <stdio.h>
#define N 7

void carga(int xArr[N], int i)
{

    if (i < N)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &xArr[i]);
        carga(xArr, i + 1);
    }
}

void mostrar(int xArr[N], int i)
{
    if (i < N)
    {
        mostrar(xArr, i + 1);
        printf("Componente Nro %d: %d \n", i, xArr[i]);
    }
}

void contarPoN(int xArr[N], int i, int &xContP, int &xContN)
{
    if (i < N)
    {
        if (xArr[i] >= 0)
        {
            xContP++;
            contarPoN(xArr, i + 1, xContP, xContN);
        }
        else
        {
            xContN++;
            contarPoN(xArr, i + 1, xContP, xContN);
        }
    }
    return;
}

// Dado un arreglo de N componentes enteras hacer en forma recursiva: 
// a) Cargar el arreglo. 
// b) Mostrar el arreglo en forma invertida. 
// c) Decir cuántas componentes son positivas y cuantas negativas. (hacer una función que devuelva ambos resultados). 

int main()
{
    int arr[N], i = 0, contP = 0, contN = 0;
    carga(arr, i);
    mostrar(arr, i);
    contarPoN(arr, i, contP, contN);

    printf("La cantidad de numeros negativos es de %d y de positivos es de %d", contN, contP);
}