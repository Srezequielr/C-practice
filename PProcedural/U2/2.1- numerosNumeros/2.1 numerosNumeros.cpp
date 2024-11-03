#include <stdio.h>
#define N 20

void carga(int arreglo[N]){
    int i;

    for(i = 0; i < N; i++){
        printf("Escribir el numero %d \n", i + 1);
        scanf("%d", &arreglo[i]);
    }
    return;
}

void esCero(int arreglo[N]){
    int i = 0;
    while( arreglo[i] != 0 && i < N){
        i++;
    }
    if(i >= N){
        printf("No hay numeros igual a 0 \n");
    }else{
        printf("Unos de los numeros es 0 \n");
    }
    return;
}

void escribirPares(int arreglo[N]){
    int i, cont = 0;
    for(i = 0; i < N; i++){
            if((i + 1) % 2 == 0){
                //printf("%d \n", &arreglo[i]);
                cont++;
            }
    }
    printf("La cantidad de numeros pares es de %d", cont);
    return;
}

// Generar un arreglo con 20 números enteros y codificar un programa en C que permita:
// a) Indicar si alguno de los números generados es cero.
// b) Escribir el contenido de las componentes que se encuentren en las posiciones pares.
// c) Indicar cantidad de números pares que contiene.

int main(){
int arreglo[N];
carga(arreglo);
esCero(arreglo);
escribirPares(arreglo);
}
