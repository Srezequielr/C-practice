#include <stdio.h>
#define N 5

struct Producto{
    int codProduct;
    float precio;
    int ventas;
};

void carga(struct Producto productos[N]){
    int i;
    for(i = 0; i < N; i++){
        printf("Cargar precio del producto N%d", i + 1);
        scanf("%d", &productos[i].precio);
        productos[i].codProduct = i + 100;
    }
}

void cargaVenta(struct Producto productos[N]){
    int codProd, cantU;
    printf("Ingrese codigo del producto (0 para cancelar): ");
    scanf("%d", &codProd);

    while(codProd != 0){
        printf("ingrese cantidad de unidades vendidas");
        scanf("%d", &cantU);
        productos[codProd - 100].ventas = productos[codProd - 100].ventas + cantU;
        printf("Ingrese codigo del producto (0 para cancelar): ");
        scanf("%d", &codProd);
    }

}

void totalXProd(struct Producto productos[N]){
    int i;
    printf("El total vendido de cada uno de los productos es de: \n");
    for(i = 0; i < N; i++){
        printf("-%d \n", productos[i].ventas);
    }
}

int main(){
    Producto productos[N];
    carga(productos);
    cargaVenta(productos);
    totalXProd(productos);
}
