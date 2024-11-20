#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int numOp;
    float importe;
    int tipOp;
} Operacion;

struct nodo
{
    Operacion dato;
    struct nodo *siguiente;
};

typedef struct nodo *Puntero;

void crearLista(Puntero &xp)
{
    xp = NULL;
}

void insertar(Puntero &xp)
{
    Puntero nuevoNodo;
    int tipo;
    printf("Ingresar numero de operacion <Cancelar con 0>: ");
    scanf("%d", &tipo);
    while (tipo != 0)
    {
        nuevoNodo = (Puntero)malloc(sizeof(struct nodo));
        nuevoNodo->dato.numOp = tipo;
        printf("Ingrese importe de la operacion: ");
        scanf("%f", &nuevoNodo->dato.importe);
        printf("Ingrese tipo de la operacion\n1: cobro 2: pago\n");
        scanf("%d", &nuevoNodo->dato.tipOp);

        nuevoNodo->siguiente = xp;
        xp = nuevoNodo;

        printf("Ingresar numero de operacion <Cancelar con 0>: ");
        scanf("%d", &tipo);
    }
}

void mostrarMayores(Puntero xp, int &mayor)
{
    if (xp != NULL)
    {
        if (mayor < xp->dato.importe && xp->dato.tipOp == 1)
        {
            mayor = xp->dato.importe;
        }
        mostrarMayores(xp->siguiente, mayor);
        if (mayor == xp->dato.importe && xp->dato.tipOp == 1)
        {
            printf("La operacion N %d tiene el importe mayor \n", xp->dato.numOp);
        }
    }
}

void cargaArchivo(Puntero xp, FILE *archivo)
{
    Operacion aux;
    while (xp != NULL)
    {
        if (xp->dato.tipOp == 2)
        {
            aux = xp->dato;
            fwrite(&aux, sizeof(aux), 1, archivo);
        }
        xp = xp->siguiente;
    }
}

void borrarLista(Puntero &xp)
{
    if (xp != NULL)
    {
        borrarLista(xp->siguiente);
        free(xp);
    }
}

float calcProm(FILE *archivo)
{
    float acum = 0;
    int cont = 0;
    Operacion op;
    rewind(archivo);
    fread(&op, sizeof(op), 1, archivo);
    while (feof(archivo) == 0)
    {
        acum += op.importe;
        cont++;
        fread(&op, sizeof(op), 1, archivo);
    }
    return (acum / cont);
}

void eliminarPagos(FILE *original, FILE *nuevo)
{
    Operacion op;
    rewind(original);
    fread(&op, sizeof(op), 1, original);
    while (feof(original) == 0)
    {
        if (op.importe > 500)
        {
            fwrite(&op, sizeof(op), 1, nuevo);
        }
        fread(&op, sizeof(op), 1, original);
    }
    delete ("Importes.dat");
    rename("Nuevo.dat", "Importes.dat");
}

// Se registra la información de las operaciones realizadas por un cajero durante un fin de semana. De cada operación se conoce: numero de operación, importe y tipo de operación (1: cobro; 2: pago).
// Utilizando funciones óptimas realice lo siguiente:
// a) Genere una lista con la información de las operaciones.
// b) Indique cual es el/los numero/s de mayor importe cobrado. (usar una función recursiva)
// c) Con la información de la lista genere un archivo con los datos de los pagos realizados.
// d) Eliminar la lista generada.
// e) Indicar en el principal el importe promedio de los pagos realizados.
// f) Eliminar del archivo los pagos menores a $500.

int main()
{
    Puntero cabeza;
    FILE *archivo, *archivo2;
    float promedio;

    // Manejo de la lista
    int mayor = 0;
    crearLista(cabeza);
    insertar(cabeza);
    mostrarMayores(cabeza, mayor);
    // -----------------

    // Manejo del archivo
    if ((archivo = fopen("Importes.dat", "w+")) == NULL)
    {
        printf("El archivo no se pudo crear/abrir");
    }
    else
    {
        cargaArchivo(cabeza, archivo);
        borrarLista(cabeza);
        promedio = calcProm(archivo);
        printf("El promedio de los pagos es de: %f", promedio);

        if ((archivo2 = fopen("Nuevo.dat", "w+")) == NULL)
        {
            printf("El archivo no se pudo crear/abrir");
        }
        else
        {
            eliminarPagos(archivo, archivo2);
            fclose(archivo2);
        }
        fclose(archivo);
    }
    // ---------------
}