#include <stdio.h>
#define N 5

struct Producto
{
    int codProduct;
    float precio = 0;
    int ventas = 0;
};

void carga(struct Producto productos[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Cargar precio del producto N%d: ", i + 100);
        scanf("%d", &productos[i].precio);
        productos[i].codProduct = i + 100;
    }
}

void cargaVenta(struct Producto productos[N])
{
    int codProd, cantU;
    printf("Ingrese codigo del producto (0 para cancelar): ");
    scanf("%d", &codProd);

    while (codProd != 0)
    {
        printf("ingrese cantidad de unidades vendidas: ");
        scanf("%d", &cantU);
        productos[codProd - 100].ventas = productos[codProd - 100].ventas + cantU;
        printf("Ingrese codigo del producto (0 para cancelar): ");
        scanf("%d", &codProd);
    }
}

void totalXProd(struct Producto productos[N])
{
    int i;
    printf("El total vendido de cada uno de los productos es de: \n");
    for (i = 0; i < N; i++)
    {
        printf(". %d \n", productos[i].ventas);
    }
}

int calcMayImpUni(struct Producto productos[N], int &codMayImp)
{
    int codMayUVend, maxVend = 0, maxImp = 0, i;

    for (i = 0; i < N; i++)
    {
        if (maxVend < productos[i].ventas)
        {
            maxVend = productos[i].ventas;
            codMayUVend = i;
        }
        if (maxImp < (productos[i].precio * productos[i].ventas))
        {
            maxImp = productos[i].precio * productos[i].ventas;
            codMayImp = i;
        }
    }
    return codMayUVend;
}

// Una industria comercializa 70 productos codificados entre 100 y 169. De cada producto se conoce el código de producto y precio unitario. Además, se cuenta con la información de las ventas realizadas durante el fin de semana. Por cada venta se ingresa código de producto y cantidad de unidades, finalizando el ingreso con código de producto igual a cero.
// Se pide realizar un programa en C, que utilizando funciones óptimas y estructuras adecuadas permita:
// 1. Total de unidades vendidas de cada uno de los productos.
// 2. Indicar en el main el código del producto que recaudó el mayor importe y la cantidad de unidades vendidas.
// 3. En función del total de unidades vendidas, decir de cuantos productos se vendieron 20, 21, 22.. 50 unidades.

int main()
{
    Producto productos[N];
    int codMayorImp, codMayUVendidas;
    carga(productos);
    cargaVenta(productos);
    totalXProd(productos);
    codMayUVendidas = calcMayImpUni(productos, codMayorImp);
    printf("El codigo del articulo mas vendido es %d y el articulo con mayor recaudacion es %d", codMayUVendidas, codMayorImp);
    
}
