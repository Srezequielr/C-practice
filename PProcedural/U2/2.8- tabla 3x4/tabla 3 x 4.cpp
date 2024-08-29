#include <stdio.h>
#include <time.h>
#define F 3
#define C 4

void carga(int tabla[F][C]){
    int i, j;
    for(i = 0; i < F; i++){
        for(j = 0; j < C; j++){
            printf("Ingrese el numero de la fila %d columna %d: ", i, j);
            scanf("%d", &tabla[i][j]);
        }
    }
}

void sumaImpar(int tabla[F][C]){
    int i, j, acum = 0;
    for(i = 0; i < F; i++){
        for(j = 0; j < C; j++){
            if(tabla[i][j] % 2 != 0)
                acum += tabla[i][j];
        }
    }
    printf("La suma de los numeros impares es de %d", acum);
}

int main(){
    int tabla[F][C];
    carga(tabla);
    sumaImpar(tabla);
}


//pertile agustin
