#include <stdio.h>
#define N 5

struct Empleado
{
    char sexo;
    int edad;
};

void cargaRecursiva(struct Empleado empleados[N], int i)
{
    if (i < N)
    {
        printf("Ingrese sexo del empleado: ");
        scanf("%c", &empleados[i].sexo);
        while (getchar() != '\n')
            ;
        printf("Ingese edad del empleado: ");
        scanf("%d", &empleados[i].edad);
        while (getchar() != '\n')
            ;
        cargaRecursiva(empleados, i + 1);
    }
}

int contarRecursivo(struct Empleado empleados[N], int i, int cantMayores)
{
    if (i < N)
    {
        if (empleados[i].edad > 30)
        {
            cantMayores++;
        }
        return contarRecursivo(empleados, i + 1, cantMayores);
    }
    else
    {
        return cantMayores;
    }
}

int calcPromRec(struct Empleado empleados[N], int i, int prom, int cont)
{
    if (i < N)
    {
        if (empleados[i].sexo == 'F')
        {
            prom += empleados[i].edad;
            return calcPromRec(empleados, i + 1, prom, cont + 1);
        }
        else
        {
            return calcPromRec(empleados, i + 1, prom, cont);
        }
    }
    else
    {
        return prom / cont;
    }
}

// Se conoce la edad y el sexo (codificado F: femenino, M: masculino) de 32 personas que trabajan en una empresa.
// Realizar un programa que a través de funciones recursivas permita:
// a) Cargar la información en una estructura optima.
// b) Indicar en el programa principal cantidad de personas mayores de 30 años.
// c) Calcular y mostrar en el programa principal la edad promedio de las mujeres.

int main()
{
    Empleado empleados[N];
    int cantMayores = 0, i = 0, prom = 0, cont = 0;
    cargaRecursiva(empleados, i);
    cantMayores = contarRecursivo(empleados, i, cantMayores);
    printf("La cantidad de empleados mayores a 30 años son %d\n", cantMayores);

    prom = calcPromRec(empleados, i, prom, cont);
    printf("El promedio de edad de mujeres es de %d", prom);
}