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

int contarPoN(int xArr[N], int i, int xContP, int &xContN)
{
    if (i != N)
    {
        if (xArr[i] >= 0)
        {
            contarPoN(xArr, i + 1, xContP + 1, xContN);
        }
        else
        {
            xContN++;
            contarPoN(xArr, i+1, xContP, xContN);
        }
    } else{
        return xContP;
    }
}

int main()
{
    int arr[N], i = 0, contP = 0, contN = 0;
    carga(arr, i);
    mostrar(arr, i);
    contN = contarPoN(arr, i, contP, contN);

    printf("La cantidad e numeros negativos es de %d y de positivos es de %d", contN, contP);
}