#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[10];
    int numReg;
    char resultado;
} Alumno;

void carga(FILE *archivo)
{
    Alumno alu;

    printf("Ingrese nombre del alumno <Cancelar con fin>: ");
    scanf("%s", &alu.nombre);
    while (char c = getchar() != '\n')
        ;
    while (strcmp(alu.nombre, "fin") != 0)
    {
        printf("Ingrese numero de registro del alumno: ");
        scanf("%d", &alu.numReg);
        while (char c = getchar() != '\n')
            ;
        printf("Ingresar resultado de parcial (A: Aprobado, R: Reprobado): ");
        scanf("%c", &alu.resultado);
        while (char c = getchar() != '\n')
            ;
        fwrite(&alu, sizeof(alu), 1, archivo);
        printf("Ingrese nombre del alumno <Cancelar con fin>: ");
        scanf("%s", &alu.nombre);
        while (char c = getchar() != '\n')
            ;
    }
}

void mostrarAlumnos(FILE *archivo)
{
    Alumno alu;
    rewind(archivo);
    fread(&alu, sizeof(alu), 1, archivo);
    printf("Datos de los alumnos de Procedural\n");
    while (feof(archivo) == 0)
    {
        printf("- Nombre del alumno: %s\n", alu.nombre);
        printf("- Numero de registro del alumno: %d\n", alu.numReg);
        printf("- Resultado del parcial del alumno: %c\n", alu.resultado);
        fread(&alu, sizeof(alu), 1, archivo);
    }
}

// Realizar en Lenguaje C los siguientes programas:
// Programa 1:
// a) Generar un archivo alumnosPP.dat que contiene la siguiente información correspondiente a los alumnos que cursan la materia Programación Procedural: Nombre, Numero de Registro y Resultado de un parcial (‘A’: Aprobado – ‘R’: Reprobado). La información se ingresa ordenada por Número de Registro.
// b) Codificar una función que permita mostrar la información de cada uno de los alumnos.
// Programa 2:
// a) Generar un archivo alumnosAL.dat que contiene la siguiente información correspondiente a los alumnos que cursan la materia Algebra Lineal: Nombre, Numero de Registro y Resultado de un parcial (‘A’: Aprobado – ‘R’: Reprobado).
// b) Codificar una función que permita mostrar la información de cada uno de los alumnos

int main()
{
    FILE *archivoProcedural, *archivoAlgebra;

    // Programa 1
    if ((archivoProcedural = fopen("alumnosPP.dat", "w+")) == NULL)
    {
        printf("El archivo de procedural no pudo ser creado/abierto\n");
    }
    else
    {
        printf("------ Archivo procedural ------\n");
        carga(archivoProcedural);
        mostrarAlumnos(archivoProcedural);
    }
    // ---------

    // Programa 2
    if ((archivoAlgebra = fopen("alumnosAL.dat", "w+")))
    {
        printf("------ Archivo algebra ------\n");
        carga(archivoAlgebra);
        mostrarAlumnos(archivoAlgebra);
    }
    // ---------
}