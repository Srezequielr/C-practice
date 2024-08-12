#include <stdio.h>
#include <string.h>
#define N 5

struct Articulo{
    int codigo;
    char nombre[20];
    float precio;
    int ventas = 0;
    int stock;
};

void menu(){
    printf("Bulonera Rawson \n");
    printf("1: Cargar producto \n");
    printf("2: Registrar venta \n");
    printf("3: Ver articulos sin stock \n");
    printf("4: Ver stock de un  producto \n");
    printf("5: Ver monto total por ventas de productos \n");
    return;
}

void carga(struct Articulo articulos[N]){
    int i;
    for(i = 0; i < N; i++){
        printf("Ingrese nombre del producto nro %d: ", i + 1);
        scanf("%s", &articulos[i].nombre);
        printf("Ingrese precio del articulo: ");
        scanf("%f", &articulos[i].precio);
        printf("Ingresar stock del producto: ");
        scanf("%d", &articulos[i].stock);
        articulos[i].codigo = i + 1;
    }
    return;
}

void caja(struct Articulo articulos[N]){
    int cant, bandera = 0, i = 0;
    char nombre[20];
    printf("Ingrese nombre del producto vendido (finalizar con 'fin'): ");
    scanf("%s", &nombre);
    while(strcmp(nombre, "fin") != 0){
        while(strcmp(nombre, articulos[i].nombre) != 0 && i < N){
            i++;
        }
        if(i >= N){
            printf("iteracion detenida en: %d \n", i);
            printf("El producto que quiere vender no existe, intente de nuevo \n");
        } else{
            printf("Ingrese unidades vendidas ");
            scanf("%d", &cant);
            if(cant > articulos[i].stock){
                printf("No hay stock suficiente \n");
            } else{
                articulos[i].stock = articulos[i].stock - cant;
                articulos[i].ventas = articulos[i].ventas + cant;
                printf("¡Venta exitosa! \n Stock restante: %d \n", articulos[i].stock);
            }
           // printf("El producto encontrado tiene ID de %d", i);
        }
        printf("Ingrese nombre del producto vendido (finalizar con 'fin'): ");
        scanf("%s", &nombre);
    }
    return;
}

void verNoStock(struct Articulo articulos[N]){
    int i;
    printf("Los productos sin stock son:\n");
    for(i = 0; i < N; i++){
        if(articulos[i].stock == 0){
            printf("- %s\n", articulos[i].nombre);
        }
    }
    return;
}

void buscarXID(struct Articulo articulos[N]){
    int id;
    printf("Ingresar ID de producto");
    scanf("%d", &id);
    if(id > N){
        printf("Producto no encontrado");
    } else{
        printf("El stock de %s es de %d unidades.", articulos[id].nombre, articulos[id].stock);
    }
    return;
}

void verRecTotal(struct Articulo articulos[N]){
    float acum = 0;
    int i;
    for(i = 0; i < N; i++){
        acum = acum + (articulos[i].ventas * articulos[i].precio);
    }
    printf("El total de recaudado es de %f \n", acum);
    return;
}

int main(){
    int bandera = 1, opcion;
    Articulo articulos[N];
    while(bandera != 0){
        menu();
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                carga(articulos);
            break;
            case 2:
                caja(articulos);
            break;
            case 3:
                verNoStock(articulos);
            break;
            case 4:
                buscarXID(articulos);
            break;
            case 5:
                verRecTotal(articulos);
            break;

        }
        printf("Desea hacer otra operacion? 0 para cancelar ");
        scanf("%d", &bandera);
    }
    return 0;
}
