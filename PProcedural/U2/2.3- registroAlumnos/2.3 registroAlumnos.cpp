#include <stdio.h>
#include <string.h>
#define N 10

struct Alumno{
char nombre[20];
char apellido[20];
int dni;
};

void carga(struct Alumno alumnos[N]){
    int i;
    for(i = 0; i < N; i++){
        printf("Ingrese nombre del alumno Nro %d ", i + 1);
        scanf("%s", &alumnos[i].nombre);
        printf("Ingrese apellido del alumno Nro %d ", i + 1);
        scanf("%s", &alumnos[i].apellido);
        printf("Ingrese el DNI del alumno Nro %d ", i + 1);
        scanf("%d", &alumnos[i].dni);
    }
    return;
}

void mostrar(struct Alumno alumnos[N]){
    int i;
    for(i = 0; i < N; i++){
        printf("El nombre del alumno es: ");
        puts(alumnos[i].nombre);
        printf("\n El apellido del alumno es: ");
        puts(alumnos[i].apellido);
        printf("\n El dni del alumno es: %d \n", alumnos[i].dni);
    }
    return;
}

void mayorDNI(struct Alumno alumnos[N]){
    int i, cont = 0;
    for(i = 0; i < N; i++){
        if(alumnos[i].dni > 40000000){
            cont++;
        }
    }
    printf("Los DNI mayor a 40M son: %d", cont);
    return;
}

// Generar un arreglo de registros que posea la siguiente información de 10 alumnos de procedural: Nombre, Apellido y
// DNI.
// a) Cargar los datos de los alumnos.
// b) Listar los alumnos cargados.
// c) Indicar cuántos alumnos tiene DNI mayor a 40 millones.

int main(){
    Alumno alumnos[N];
    carga(alumnos);
    mostrar(alumnos);
    mayorDNI(alumnos);
return 0;
}
