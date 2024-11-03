#include <stdio.h>
#define F 6
#define C 4

void cerear(int tabla[F][C]){
    int i, j;
    for(i = 0; i < F; i++){
        for(j = 0; j < C; j++){
            tabla[i][j] = 0;
        }
    }
}

void carga(int tabla[F][C]){
    int i, j;

    printf("Ingrese numero de area 1-6 (0 para cancelar): ");
    scanf("%d", &i);
    while(i != 0){
        printf("Ingrese el turno al que quiere asistir 1-4: ");
        scanf("%d", &tabla[i - 1][j - 1]);
        printf("\n--------------------\n");
        tabla[i][j]++;
        printf("Ingrese numero de area 1-6 (0 para cancelar): ");
        scanf("%d", &i);
    }
}

void sumTurno(int tabla[F][C]){
    int i, j;
    int acum = 0;
    for(j = 0; j < C; j++){
        acum = 0;
        for(i = 0; i < F; i++){
            acum += tabla[j][i];
        }
        printf("La cantidad de alumnos del turno %d es de: %d \n", j + 1, acum);
    }
}

int main(){
    int tabla[F][C];
    cerear(tabla);
    carga(tabla);
    sumTurno(tabla);
}
