#include <stdio.h>

#define S 6
#define T 4

void cerear(int tabla[S][T])
{
    int i, j;

    for (i = 0; i < S; i++)
    {
        for (j = 0; j < T; j++)
        {
            tabla[i][j] = 0;
        }
    }
}

void carga(int tabla[S][T])
{
    int sala, turno;

    printf("Ingrese sala tematica (1-6) <Cancelar con 0>: ");
    scanf("%d", &sala);
    while (sala != 0)
    {
        printf("Ingrete turno (1-4): ");
        scanf("%d", &turno);
        tabla[sala - 1][turno - 1]++;
        printf("Ingrese sala tematica (1-6) <Cancelar con 0>: ");
        scanf("%d", &sala);
    }
}

void contInscriptos(int tabla[S][T])
{
    int inscriptos = 0, i, j;

    for (i = 0; i < S; i++)
    {
        printf("Inscriptos de la sala numero %d\n", i + 1);
        for (j = 0; j < T; j++)
        {
            printf("- Turno numero %d: %d\n", j + 1, tabla[i][j]);
        }
        printf("----------------\n");
    }
}

void promedio(int tabla[S][T])
{
    int promedio = 0, i, j;
    printf("Ingrese area tematica: ");
    scanf("%d", &j);
    for (i = 0; i < S; i++)
    {
        promedio += tabla[i][j - 1];
    }
    promedio = promedio / T;
    printf("El promedio de inscriptos en el area tematica seleccionada es de %d\n", promedio);
}

void mostrar(int tabla[S][T])
{
    int i, j;
    for (i = 0; i < S; i++)
    {
        for (j = 0; j < T; j++)
        {
            printf(" %d |", tabla[i][j]);
        }
        printf("\n");
    }
}

// En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa un área
// temática. En cada sala se dictan 4 conferencias en distintos turnos. Por cada interesado se ingresa número del área
// temática (1-6), y turno al que quiere asistir (1-4). La Facultad desea llevar un registro de la cantidad de alumnos
// inscriptos en cada área y en cada turno, para ello realizar los siguientes items:
// a) Carga de los datos. La carga es desordenada, cada alumno indica área y turno. No se sabe la cantidad de alumnos.
// b) Indicar la cantidad de inscriptos en cada turno de cada área.
// c) Dada un área temática, indicar el promedio de inscriptos.

int main()
{
    int tabla[S][T];
    cerear(tabla);
    carga(tabla);
    contInscriptos(tabla);
    promedio(tabla);
    mostrar(tabla);
}