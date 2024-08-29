#include <stdio.h>
#include <string.h>
#define N 5


struct Articulo{
    int codArt;
    char nombre[20];
    float precio;
    int stock;
    int ventas = 0;
};

/*Ejercicio 2
Un local comercial de ventas de repuestos de automotores desea obtener cierta
información sobre todas las ventas registradas en un periodo de tiempo dado.
El comercio cuenta con 250 artículos, almacenados en una estructura y de los
cuales se conocen los siguientes datos: Código, Nombre, Precio Unitario y Stock.
Se procesan las ventas y los datos ingresados de cada una son: Nombre del artículo, Cantidad de unidades vendidas (con esta información actualizar el stock de cada artículo). El ingreso de ventas termina con nombre igual “FIN”.
Se pide realizar un programa en C, que utilizando subprogramas óptimos y
estructuras adecuadas permita:
1. Procesar las ventas registradas en ese periodo de tiempo.

2. Mostrar en el main la cantidad de artículos que quedaron con stock nulo
y cuantos tienen un precio mayor a $7000.

3. Imprimir los nombres de los 20 artículos que quedaron con mayor stock.

4. Indicar para cada artículo el monto total obtenido por ventas.*/

void carga(struct Articulo articulos[N]){
    int i;
    for(i = 0; i < N; i++){
        printf("Ingrese nombre del producto nro %d: ", i + 1);
        scanf("%s", &articulos[i].nombre);
        printf("Ingrese precio del articulo: ");
        scanf("%f", &articulos[i].precio);
        printf("Ingresar stock del producto: ");
        scanf("%d", &articulos[i].stock);
        articulos[i].codArt = i + 1;
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
                printf("�Venta exitosa! \n Stock restante: %d \n", articulos[i].stock);
            }
           // printf("El producto encontrado tiene ID de %d", i);
        }
        printf("Ingrese nombre del producto vendido (finalizar con 'fin'): ");
        scanf("%s", &nombre);
    }
    return;
}

void menu(){
    printf("Fiat Rochi \n");
    printf("1: Cargar producto \n");
    printf("2: Registrar venta \n");
    printf("3: Ver cantidad de articulos sin stock y con precios mayor a 7000\n");
    printf("4: Ver articulos con mayor stock \n");
    printf("5: Ver total de recaudacion de todos los articulos \n");
    return;
}

void noStockPSieteMil(struct Articulo articulos[N], int &precMasSieteMil, int &noStock){
    int i;

    for(i = 0; i < N; i++){
        if(articulos[i].stock == 0){
            noStock++;
        }
        if(articulos[i].precio > 7000){
            precMasSieteMil++;
        }
    }
}


int main(){
    int bandera = 1, opcion, masSieteMil = 0, noStock = 0;
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
                noStockPSieteMil(articulos, masSieteMil, noStock);
            break;
         /* case 4:
                buscarXID(articulos);
            break;
            case 5:
                verRecTotal(articulos);
            break; */

        }
        printf("Desea hacer otra operacion? 0 para cancelar ");
        scanf("%d", &bandera);
    }


    return 0;
}
