#include <stdio.h>
#include <string.h>
#define S 6
#define T 4

struct Sala
{
    int cupo;
    char nombre[20];
};

void cargaSalas(struct Sala salas[S])
{
    int i;
    for (i = 0; i < S; i++)
    {
        printf("Ingrese el nombre de la sala numero %d: ", i + 1);
        scanf("%s", &salas[i].nombre);
        printf("Ingrese cupo de la sala: ");
        scanf("%d", &salas[i].cupo);
    }
}

void cereo(int tabla[S][T])
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

void inscripcion(int tabla[S][T], Sala salas[S])
{
    int i, j;
    printf("Ingresar sala tematica (1-6) <0 para cancelar>: ");
    scanf("%d", &i);
    while (i != 0)
    {
        printf("Ingrese turno (1-4): ");
        scanf("%d", &j);
        if (salas[i].cupo == 0)
        {
            printf("Sala llena en este turno, intente con otra sala u horario");
        }
        else
        {
            tabla[i][j]++;
            salas[i].cupo--;
            printf("Inscripcion registrada correctamente");
        }
        printf("Ingresar sala tematica (1-6) <0 para cancelar>: ");
        scanf("%d", &i);
    }
}

void mostrar(int tabla[S][T])
{
    int i, j;

    for (i = 0; i < S; i++)
    {
        for (j = 0; j < T; j++)
        {
            printf("%d", tabla[i][j]);
        }
        printf("\n");
    }
}

void mayorYmenorIns(int tabla[S][T], Sala salas[S])
{
    int i, j, mayor, menor, codMenor, codMayor;

    for (i = 0; i < S; i++)
    {
        mayor = 0;
        menor = 999999;
        for (i = 0; i < S; i++)
        {
            if (mayor < tabla[i][j])
            {
                mayor = tabla[i][j];
                codMayor = j;
            }
            if (menor > tabla[i][j])
            {
                menor = tabla[i][j];
                codMenor = j;
            }
        }
        printf("Del area tematica %s el turno con mas inscriptos es el %d y con mas inscriptos es el %d", salas[S].nombre, codMayor + 1, codMenor + 1);
    }
}

void areaMenosIns(int tabla[S][T], Sala salas[S])
{
    int i, j, menor, codMenor, cont;

    for (i = 0; i < S; i++)
    {
        cont = 0;
        for (j = 0; j < T; j++)
        {
            cont += tabla[i][j];
        }
        if (menor > cont)
        {
            codMenor = i;
            menor = cont;
        }
    }
    printf("La sala tematica con menos inscriptos es %s", salas[codMenor].nombre);
}

void calcProm(int tabla[S][T], Sala salas[S])
{
    char nombre[20];
    int i = 0, j, prom;

    printf("Ingrese nombre de la sala: ");
    scanf("%d", &nombre);

    while (strcmp(nombre, salas[i].nombre) != 0 && i < S)
    {
        i++;
    }
    if (i == S)
    {
        printf("La sala no se encontro\n");
    }
    else
    {
        for (j = 0; j < T; j++)
        {
            prom += tabla[i][j];
        }
        prom = prom / T;
        printf("El promedio del area tematica es de %d", prom);
    }
}

// En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa un área temática. En cada sala se dictarán 4 conferencias en distintos turnos. Para procesar la información, en un primer momento y por única vez se ingresa el nombre de cada una de las 6 áreas temáticas que se tratarán en el congreso y el cupo de personas para la sala donde se dictará la misma. Por cada interesado se ingresa su nombre, nombre del área temática, y número correspondiente a la conferencia a la que quiere asistir. La inscripción se realiza previa verificación del cupo de la sala. A partir de la información ingresada generar una tabla que permita responder los siguientes ítems:
// 1. Decir para cada área temática qué conferencia tuvo menos asistentes y cuál la mayor cantidad (Suponer el mayor y el menor como valores únicos).
// 2. Indicar el nombre del área temática con menos inscriptos.
// 3. Dado un nombre de área temática decir cuál fue el promedio de inscriptos.

int main()
{
    int tabla[S][T];
    Sala salas[S];
    cereo(tabla);
    cargaSalas(salas);
    inscripcion(tabla, salas);
    mayorYmenorIns(tabla, salas);
    areaMenosIns(tabla, salas);
    calcProm(tabla, salas);
    //   mostrar(tabla);
}
