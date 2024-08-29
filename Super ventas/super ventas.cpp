#include <stdio.h>
#define M 12
#define D 4


void cerear(float tabla[D][M]){
    int i, j;
    for(i = 0; i < D; i++){
        for(j = 0; j < M; j++){
            tabla[i][j] = 0;
        }
    }
}

void carga(float tabla[D][M]){
    int mes, dep;
    float importe;
    printf("Ingrese mes para cargar (Cancelar con 0): ");
    scanf("%d", &mes);
    while(mes != 0){
        printf("Ingresar departamento para cargar: ");
        scanf("%d", &dep);
        printf("Ingrese importe recaudado en el mes: ");
        scanf("%f", &importe);
        tabla[dep - 1][mes - 1] += importe;
        printf("Ingrese mes para cargar (Cancelar con 0): ");
        scanf("%d", &mes);
    }
    return;
}

int mostrarMin(float tabla[D][M]){
    int mes, i, aux;
    float minimo = 9999999;
    printf("Escribir mes a buscar");
    scanf("%d", &mes);
    for(i = 0; i < D; i++){
        if(tabla[i][mes - 1] < minimo){
                printf("Se actualizo el minimo \n");
            minimo = tabla[i][mes - 1];
            aux = i;
        }
    }
    return aux + 1;
}

float calcProm(float tabla[D][M]){
    int i, j;
    float acum;
    float prom;
    for(i = 0; i < D; i++){
        for(j = 0; j < M; j++){

        }

    }
    return prom;
}

int main(){
    float tabla[D][M], prom;
    int minimo;
    cerear(tabla);
    carga(tabla);
    minimo = mostrarMin(tabla);
    printf("El departamento que menos recaudo del mes seleccionado es el departamento %d", minimo);
    prom = calcProm(tabla);
    return 0;
}



	//while(getchar() != '\n'); Evitar salto de linea con el uso de gets
