#include <stdio.h>
#define P 50
#define C 100
#define PR 22

struct Producto
{
    int codigo;
    float precioCost;
    int stock = 0;
};

struct Compra
{
    int codProd;
    int numProv;
    int cant;
};

struct Provedor
{
    char nombre;
    int numeroProv;
};

void menu()
{
    printf("Cafe America \n");
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
        printf("Ingrese precio de proveedor");
        scanf("%f", &productos[i].precioCost);
    }
    return;
}

void cargaProve(struct Provedor provedores[PR])
{
    return;
}

void regiComp(struct Compra compras[C])
{
    return;
}

void invXProd(struct Producto productos[P])
{
    return;
}

void provMasDiez(struct Provedor provedores[PR])
{
    return;
}

void buscarProv(struct Provedor provedores[PR])
{
    return;
}

int main()
{
    Producto productos[P];
    Compra compras[C];
    Provedor provedores[PR];
    int opcion;
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
            regiComp(compras);
            break;
        case 4:
            invXProd(productos);
            break;
        case 5:
            provMasDiez(provedores);
            break;
        case 6:
            buscarProv(provedores);
            break;
        }

        printf("Desea hacer otra operacion? 0 para cancelar ");
        scanf("%d", &opcion);
    }
    return 0;
}
