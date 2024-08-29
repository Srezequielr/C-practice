#include <stdio.h>
#define S 3
#define C 2

struct Sala{
    int cupo;
    char nombre[20];
};

void cargaSalas(struct Sala salas[S]){
    int i;
    for(i = 0; i < S; i++){
        printf("Ingrese el nombre de la sala numero %d: ", i + 1);
        scanf("%s", &salas[i].nombre);
        printf("Ingrese cupo de la sala: ");
        scanf("%d", &salas[i].cupo);
    }
}

void cereo(int tabla[S][C]){
    int i, j;

    for(i = 0; i < S; i++){
        for(j = 0; j < C; j++){
            tabla[i][j] = 0;
        }
    }
}

void mostrar(int tabla[S][C]){
    int i, j;

    for(i = 0; i < S; i++){
        for(j = 0; j < C; j++){
            printf("%d", tabla[i][j]);
        }
        printf("\n");
    }
}

//void inscripcion(int tabla, )

int main(){
    int tabla[S][C];
    Sala salas[S];
    cereo(tabla);
    cargaSalas(salas);
  //  inscripcion(tabla, salas)
  mostrar(tabla);
}
