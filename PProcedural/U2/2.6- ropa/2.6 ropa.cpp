#include <stdio.h>
#include <string.h>
#define P 5
#define PR 2

struct Producto
{
    int codigo;
    float precioCost;
    int stock = 0;
};

struct Provedor
{
    char nombre[20];
    int numeroProv;
    int cantVentas = 0;
};

void menu()
{
    printf("1: Cargar productos \n");
    printf("2: Cargar Proveedores \n");
    printf("3: Registrar Compra \n");
    printf("4: Ver inversion por producto \n");
    printf("5: Ver proveedores con mas de 10 compras \n");
    printf("6: Buscar proveedor \n");
    return;
}

void cargaProduct(struct Producto productos[P])
{
    int i;
    for (i = 0; i < P; i++)
    {
        printf("Ingrese precio de producto: ");
        scanf("%f", &productos[i].precioCost);
        productos[i].codigo = i + 1;
    }
    return;
}

void cargaProve(struct Provedor provedores[PR])
{
    int i;
    for (i = 0; i < PR; i++)
    {
        printf("Ingrese nombre del proveedor: ");
        scanf("%s", &provedores[i].nombre);
        provedores[i].numeroProv = i + 1001;
    }
    return;
}

void regiComp(struct Producto productos[P], struct Provedor provedores[PR])
{
    int cod, numProv, cantComp;
    printf("Ingrese el codigo de producto que desea comprar <0 para cancelar>: ");
    scanf("%d", &cod);
    while (cod != 0)
    {
        printf("Ingrese numero de proveedor: ");
        scanf("%d", &numProv);
        printf("Ingrese cantidad de productos comprados: ");
        scanf("%d", &cantComp);
        productos[cod - 1].stock += cantComp;
        provedores[numProv - 1001].cantVentas++;

        printf("Ingrese el codigo de producto que desea comprar <0 para cancelar>: ");
        scanf("%d", &cod);
    }
    return;
}

void invXProd(struct Producto productos[P])
{
    int i;
    float totalInv = 0;
    for (i = 0; i < P; i++)
    {
        totalInv += productos[i].precioCost * productos[i].stock;
        printf("En el producto con codigo %d tiene una inversion total de $%.2f\n", i + 1, totalInv);
        totalInv = 0;
    }
    return;
}

int provMasDiez(struct Provedor provedores[PR], struct Provedor provMasDiez[PR])
{
    int j = 0, i;
    for (i = 0; i < PR; i++)
    {
        if (provedores[i].cantVentas > 10)
        {
            provMasDiez[j] = provedores[i];
            j++;
        }
    }
    return j;
}

void ordenarYMostrar(struct Provedor proveedores[PR], int j)
{
    int i, k, cota;
    struct Provedor aux;
    k = 1;
    cota = j - 1;
    while (k != -1)
    {
        k = -1;
        for (i = 0; i < cota; i++)
        {
            if (strcmp(proveedores[i].nombre, proveedores[i + 1].nombre) > 0)
            {
                aux = proveedores[i];
                proveedores[i] = proveedores[i + 1];
                proveedores[i + 1] = aux;
                k = i;
            }
        }
        cota = k;
    }

    for (i = 0; i < j; i++)
    {
        printf("Nombre del proveedor: %s\nNumero del proveedor: %d\nCantidad de unidades compradas: %d", proveedores[i].nombre, proveedores[i].numeroProv, proveedores[i].cantVentas);
    }
}

void buscarProv(struct Provedor provedores[PR], int j)
{
    char busqueda[20];
    int i = 0;
    printf("Ingresar proveedor que se quiere buscar: ");
    scanf("%s", &busqueda);

    while (strcmp(busqueda, provedores[i].nombre) != 0 && i < j)
    {
        i++;
    }
    if (i == j)
    {
        printf("No se encontro el proveedor");
    }
    else
    {
        printf("Se realizaron %d compras", provedores[i].cantVentas);
    }

    return;
}

// Una tienda de ropa comercializa 50 productos diferentes. Por cada producto se conoce: código (número entero que
// varía entre 1 y 50), precio de costo y stock.
// La tienda hace compras a 22 proveedores, de los cuales se conoce: Nombre y Número de Proveedor (es un número
// entre 1000 y 1022).
// Se pide redactar un algoritmo en C que, usando estructuras de datos óptimas y subprogramas eficientes, permita:
// a) Almacenar en estructuras de datos adecuadas la información de los Productos y de los Proveedores.
// b) Procesar las compras realizadas a los Proveedores, sabiendo que por cada compra se conoce el Número de
// Proveedor, Código de Producto y Cantidad de unidades compradas. Con la información de cada compra se debe
// actualizar el stock del producto y contar para cada proveedor la compra realizada.
// c) Informar cuánto dinero hay invertido en cada producto.
// d) Generar una nueva estructura de datos que contenga todos los datos de aquellos Proveedores a quienes se les haya
// realizado más de 10 compras.
// e) Mostrar la estructura de datos generada en el inciso d) ordenada alfabéticamente por Nombre de proveedor.
// f) Ingresar por teclado un Nombre de proveedor e informar su Número y cantidad de compras realizadas. Nota: Utilizar
// la estructura de datos generada en el inciso d).

int main()
{
    Producto productos[P];
    Provedor provedores[PR], provMasVent[PR];
    int j;
    int opcion = -1;
    while (opcion != 0)
    {
        menu();
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            cargaProduct(productos);
            break;
        case 2:
            cargaProve(provedores);
            break;
        case 3:
            regiComp(productos, provedores);
            break;
        case 4:
            invXProd(productos);
            break;
        case 5:
            j = provMasDiez(provedores, provMasVent);
            ordenarYMostrar(provMasVent, j);
            break;
        case 6:
            buscarProv(provedores, j);
            break;
        }
        menu();
        printf("Desea hacer otra operacion? 0 para cancelar ");
        scanf("%d", &opcion);
    }
    return 0;
}
