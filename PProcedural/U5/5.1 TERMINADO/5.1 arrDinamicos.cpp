#include <stdio.h>
#include <stdlib.h>

int *crearCargarArr(int b)
{
    int i;
    int *arre = (int *)malloc(b * sizeof(int));
    if (arre == NULL)
    {
        printf("Fallo la creacion del arreglo");
    }
    else
    {
        printf("------- Ingrese los valores del arreglo -------\n");
        for (i = 0; i < b; i++)
        {
            printf("Ingrese valor %d: ", i + 1);
            scanf("%d", &arre[i]);
        }
    }

    return arre;
}

int calcEscalar(int *arre1, int *arre2, int n, int i, int prodEscalar)
{

    if (i < n)
    {
        prodEscalar += arre1[i] * arre2[i];
        return calcEscalar(arre1, arre2, n, i + 1, prodEscalar);
    }
    else
    {
        return prodEscalar;
    }
}

int *cargaSubArre(int *arre, int n)
{
    int pares = 0, i, subI = 0, *subArre;

    for (i = 0; i < n; i++)
    {
        if (arre[i] % 2 == 0)
        {
            pares++;
        }
    }

    subArre = (int *)malloc(pares * sizeof(int));
    if (subArre == NULL)
    {
        printf("Fallo la carga del arreglo");
    }
    else
    {
        for (i = 0; i < pares; i++)
        {
            if (arre[i] % 2 == 0)
            {
                subArre[subI] = arre[i];
                subI++;
            }
        }
    }
    return arre;
}

// Escribir un programa en lenguaje C que usando funciones permita:
// a) Crear y cargar 2 arreglos dinámicos de componentes enteras MxM (mismo tamaño) ingresada por teclado.
// b) Calcular el producto escalar.
// El producto escalar es una operación donde al multiplicar dos arreglos se obtiene un único valor.
// A * B = A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1]
// c) Generar una nueva estructura con los valores pares contenidos en uno de los arreglos (realizar un subprograma
// que solicite memoria para la nueva estructura y la devuelva cargada).

int main()
{
    int *arre1, *arre2, *subArre, n, i = 0, prodEscalar = 0;

    printf("Ingrese longitud de los arreglos: ");
    scanf("%d", &n);

    arre1 = crearCargarArr(n);
    arre2 = crearCargarArr(n);

    prodEscalar = calcEscalar(arre1, arre2, n, i, prodEscalar);
    printf("El producto escalar de los dos arreglos es de %d", prodEscalar);

    subArre = cargaSubArre(arre1, n);
}