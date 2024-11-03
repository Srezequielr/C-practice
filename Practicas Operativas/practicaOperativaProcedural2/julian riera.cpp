#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alumno: Julian Riera JTP: Silvina Balmaceda

typedef struct
{
    int patente;
    char marca[30];
    char modelo[30];
    int año;
} Auto;

struct Nodo
{
    Auto dato;
    struct Nodo *siguiente;
};

typedef struct Nodo *Puntero;

void crearLista(Puntero &xp)
{
    xp = NULL;
}

void insertar(Puntero &xp)
{
    int patente;
    Puntero nuevoNodo;

    printf("Ingresar numero de patente <Cancelar con 0>: ");
    scanf("%d", &patente);
    while (char c = getchar() != '\n')
        ;
    while (patente != 0)
    {
        nuevoNodo = (Puntero)malloc(sizeof(struct Nodo));
        nuevoNodo->dato.patente = patente;

        printf("Ingrese marca del vehiculo: ");
        gets(nuevoNodo->dato.marca);
        printf("Ingrese modelo del vehiculo: ");
        gets(nuevoNodo->dato.modelo);
        printf("Ingrese año del vehiculo: ");
        scanf("%d", &nuevoNodo->dato.año);

        nuevoNodo->siguiente = xp;
        xp = nuevoNodo;

        printf("Ingresar numero de patente <Cancelar con 0>: ");
        scanf("%d", &patente);
        while (char c = getchar() != '\n')
            ;
    }
}

Puntero busquedaRecursiva(Puntero xp, int pat)
{
    if (xp != NULL && xp->dato.patente != pat)
    {
        return busquedaRecursiva(xp->siguiente, pat);
    }
    else
    {
        return xp;
    }
}

void mostrarMarca(Puntero xp, char marca[30])
{
    while (xp != NULL)
    {
        if (strcmp(marca, xp->dato.marca) == 0)
        {
            printf("- Numero de patente: %d\n", xp->dato.patente);
            printf("- Marca del vehiculo: ");
            puts(xp->dato.marca);
            printf("- Modelo del vehiculo: ");
            puts(xp->dato.modelo);
            printf("- Año del vehiculo: %d\n", xp->dato.año);
            mostrarMarca(xp->siguiente, marca);
        }
        xp = xp->siguiente;
    }
}

void eliminarElemento(Puntero &xp)
{
    int patente;
    Puntero anterior, actual;
    printf("\nIngrese patente de vehiculo a eliminar: ");
    scanf("%d", &patente);
    if (xp->dato.patente == patente)
    {
        actual = xp;
        xp = xp->siguiente;
        free(actual);
    }
    else
    {
        actual = xp;
        anterior = xp;
        while (actual != NULL && actual->dato.patente != patente)
        {
            anterior = actual;
            actual = actual->siguiente;
        }
        if (actual != NULL)
        {
            anterior->siguiente = actual->siguiente;
            free(actual);
            printf("El vehiculo se elimino correctamente\n");
        }
        else
        {
            printf("El vehiculo no se encontro \n");
        }
    }
}

Puntero buscarMasAntiguo(Puntero xp, Puntero masAntiguo, int min)
{
    if (xp != NULL)
    {
        if (xp->dato.año < min)
        {
            masAntiguo = xp;
            min = masAntiguo->dato.año;
        }
        return buscarMasAntiguo(xp->siguiente, masAntiguo, min);
    }
    else
    {
        return masAntiguo;
    }
}

// Requisitos:
// 1. Creación de una lista enlazada: Crea una función que reciba una cabeza de lista y genere una lista enlazada en la cual registre información de autos: patente (número entero), marca, modelo y año.
// 2. Búsqueda recursiva de un elemento: Crea una función recursiva que reciba una patente y si se encuentra en la lista enlazada mostrar en el principal los datos del auto.
// 3. Impresión recursiva de la lista: Crear una función que reciba una marca e imprima todos los autos de esa marca.
// 4. Eliminación de un elemento por valor: Crea una función que, dado una patente elimine el nodo que contiene dicho valor en la lista enlazada.
// 5. Procesamiento de la lista: Crea una función recursiva que indique cual es el auto más antiguo. Mostrar el resultado en el principal.

void mostrarLista(Puntero xp)
{
    while (xp != NULL)
    {
        printf("- Modelo del vehiculo: ");
        puts(xp->dato.modelo);

        xp = xp->siguiente;
    }
}

int main()
{
    Puntero cabeza, patenteBuscada, masAntiguo;
    int pat, min = 3000;
    char marca[30];

    // Crear y cargar lista P1
    crearLista(cabeza);
    insertar(cabeza);
    // Fin carga y crear lista

    // Inicia busqueda recursiva P2
    printf("-------- Busqueda --------\n");
    printf("Ingrese patente a buscar: ");
    scanf("%d", &pat);
    while (char c = getchar() != '\n')
        ;
    patenteBuscada = busquedaRecursiva(cabeza, pat);
    if (patenteBuscada == NULL)
    {
        printf("El auto no fue encontrado");
    }
    else
    {
        printf("- Numero de patente: %d\n", patenteBuscada->dato.patente);
        printf("- Marca del vehiculo: ");
        puts(patenteBuscada->dato.marca);
        printf("- Modelo del vehiculo: ");
        puts(patenteBuscada->dato.modelo);
        printf("- Año del vehiculo: %d\n", patenteBuscada->dato.año);
    }
    // Fin de busqueda recursiva

    // Inicia mostrar marca P3
    printf("Ingresar la marca del vehiculo: ");
    gets(marca);
    mostrarMarca(cabeza, marca);
    // Fin mostrar marca

    // Eliminar vehiculo P4
    eliminarElemento(cabeza);
    // Fin eliminar vehiculo

    // Inicio mostrar mas antiguo P5
    masAntiguo = buscarMasAntiguo(cabeza, masAntiguo, min);
    printf("- Numero de patente: %d\n", masAntiguo->dato.patente);
    printf("- Marca del vehiculo: ");
    puts(masAntiguo->dato.marca);
    printf("- Modelo del vehiculo: ");
    puts(masAntiguo->dato.modelo);
    printf("- Año del vehiculo: %d\n", masAntiguo->dato.año);
    // Fin mostrar mas antiguo

    // Mostrar adicional
    mostrarLista(cabeza);
    // Fin mostrar
}