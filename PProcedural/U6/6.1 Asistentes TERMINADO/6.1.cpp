#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    int edad;
} Asistente;

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void carga(FILE *archivo)
{
    Asistente asis;
    printf("Ingrese nombre del asistente <Terminar con fin>: ");
    gets(asis.nombre);
    fflush(stdin);
    while (strcmp(asis.nombre, "fin"))
    {
        printf("Ingrese edad del asistente: ");
        scanf("%d", &asis.edad);
        fflush(stdin);
        fwrite(&asis, sizeof(asis), 1, archivo);
        printf("Ingrese nombre del asistente <Terminar con fin>: ");
        gets(asis.nombre);
        fflush(stdin);
    }
}

void mostrarMayores(FILE *archivo)
{
    Asistente asis;
    printf("------Asistentes mayores de 40 anios------\n");
    rewind(archivo);
    fread(&asis, sizeof(asis), 1, archivo);
    while (feof(archivo) == 0)
    {
        if (asis.edad > 40)
        {
            printf("- Nombre: ");
            puts(asis.nombre);
        }
        fread(&asis, sizeof(asis), 1, archivo);
    }
}

int calcProm(FILE *archivo)
{
    Asistente asis;
    int cont = 0, acum = 0, resultado;
    rewind(archivo);
    fread(&asis, sizeof(asis), 1, archivo);
    while (feof(archivo) == 0)
    {
        cont++;
        acum += asis.edad;
        fread(&asis, sizeof(asis), 1, archivo);
    }
    resultado = acum / cont;
    return resultado;
}

int main()
{
    FILE *archivo;
    int promedio;

    if ((archivo = fopen("Datos.dat", "w+")) == NULL)
    {
        printf("El archivo no pudo ser creado/abierto");
    }
    else
    {
        carga(archivo);
        mostrarMayores(archivo);
        promedio = calcProm(archivo);
        printf("La edad promedio es de %d", promedio);
        fclose(archivo);
    }
}

// Sabado 21 de diciembre